#ifndef LIST_H
#define LIST_H

template<class T>
class List {
private:
    class Nodo {
    public:
        T info;
        Nodo* prev;
        Nodo* next;
        Nodo(const T& t = T(), Nodo* p = nullptr, Nodo* n = nullptr): info (t), prev(p), next (n){}
        ~Nodo(){delete next;}
    };
    Nodo* ultimo;
    Nodo* primo;
    unsigned int dim;

    static Nodo* copia (Nodo* p, Nodo*& l) {
        if(p==nullptr) return nullptr;
        Nodo* ris = new Nodo(p->info);
        Nodo* it = ris;
        while(p->next!=nullptr){
            p=p->next;
            it=new Nodo(p->info, it, nullptr);
            (it->prev)->next=it;
        }
        l = it;
        return ris;
    }
public:
    ~List() {delete primo;}
    List(const List& d) : primo(copia(d.primo, ultimo)), dim(d.dim){}
    List& operator=(const List& d) {
        if(this != &d) {
            delete primo;
            primo=copia(d.primo,ultimo);
            dim = d.dim;
        }
        return *this;
    }
    void insertFront(const T& t) {
        primo = new Nodo(t,nullptr,primo);
        if(primo->next==nullptr) {
            ultimo=primo;
        }
        else {
            (primo->next)->prev=primo;
        }
        dim +=1;
    }
    void insertBack(const T& t) {
        ultimo = new Nodo(t,ultimo,nullptr);
        if((ultimo->prev)==nullptr) {
            primo=ultimo;
        }
        else {
            (ultimo->prev)->next=ultimo;
        }
        dim+=1;
    }
    unsigned int getSize() const{
        return dim;
    }
    List() : ultimo(nullptr), primo(nullptr), dim(0) {};
    List(unsigned int k, const T& t): ultimo(nullptr), primo(nullptr) {
        for(unsigned int i=0; i<k; ++i)
            insertFront(t);
        dim = k;
    }

    class Iterator {
        friend class List<T>;
    private:
        Nodo* ptr;
        bool pastTheEnd;
        Iterator(Nodo* p, bool pte=false): ptr(p), pastTheEnd(pte) {}
    public:
        Iterator(): ptr(nullptr), pastTheEnd(false) {}

        T& operator*() const {
            return ptr->info;
        }

        T* operator->() const {
            return &(ptr->info);
        }

        Iterator& operator++() {
            if(ptr!= nullptr) {
                if(!pastTheEnd) {
                    if(ptr->next==nullptr) {++ptr; pastTheEnd=true;}
                    else {ptr=ptr->next;}
                }
            }
            return *this;
        }

        Iterator& operator--() {
            if(ptr!=nullptr) {
                if(pastTheEnd) {--ptr; pastTheEnd=false;}
                else ptr=ptr->prev;
            }
            return *this;
        }

        bool operator==(const Iterator& x) const {
            return ptr==x.ptr;
        }

        bool operator!=(const Iterator& x) const {
            return ptr!=x.ptr;
        }
    };

    Iterator begin() const {
        return Iterator(primo);
    }

    Iterator end() const {
        if(ultimo==nullptr) return nullptr;
        return Iterator(ultimo+1,true);
    }
};


#endif // LIST_H
