#include<iostream>
#include<string.h>
using namespace std;

struct nodo{
    char nomb[20];
    nodo *ant, *sig;
};
void cread_i(nodo *&p, nodo *&f){
    nodo *q;
    char op;
    p=NULL;
    f=NULL;
    do{
        system("cls");
        cout<<"\n\nCREANDO LISTA POR EL INICIO...";
        q=new nodo;
        cout<<"\n\nNombre: ";
        cin>>q->nomb;
        q->ant=NULL;
        q->sig=p;
        if(p==NULL){
            f=q;
        }
        else{
            p->ant=q;
        }
        p=q;
        cout<<"\n\n\t\tDesea agregar otro nodo (s/n): ";
        cin>>op;
    }while(op=='s' || op=='S');
}
void cread_f(nodo *&p, nodo *&f){
    nodo *q;
    char op;
    p=NULL;
    f=NULL;
    do{
        system("cls");
        cout<<"\n\nCREANDO LISTA POR EL FINAL...";
        q=new nodo;
        cout<<"\n\nNombre: ";
        cin>>q->nomb;
        q->sig=NULL;
        q->ant=f;
        if(p==NULL){
            p=q;
        }
        else{
            f->sig=q;
        }
        f=q;
        cout<<"\n\n\t\tDesea agregar otro nodo (s/n): ";
        cin>>op;
    }while(op=='s' || op=='S');
}
void insertad_i(nodo *&p, nodo *&f){
    nodo *q;
    system("cls");
    cout<<"\n\nINSERTANDO NODO POR EL INICIO...";
    q=new nodo;
    cout<<"\n\nNombre: ";
    cin>>q->nomb;
    q->sig=p;
    q->ant=NULL;
    if(p==NULL){
        f=q;
    }
    else{
        p->ant=q;
    }
    p=q;
}
void insertad_f(nodo *&p, nodo *&f){
    nodo *q;
    system("cls");
    cout<<"\n\nINSERTANDO NODO POR EL FINAL...";
    q=new nodo;
    cout<<"\n\nNombre: ";
    cin>>q->nomb;
    q->sig=NULL;
    q->ant=f;
    if(p==NULL){
        p=q;
    }
    else{
        f->sig=q;
    }
    f=q;
}
nodo *inserta_ad(nodo *p, char ref[]){
    nodo *q, *r, *x;
    int cen;
    if(p!=NULL){
        q=p;
        cen=0;
        while(strcmp(q->nomb,ref)!=0 and cen==0){
            if(q->sig!=NULL){
                q=q->sig;
            }
            else{
                cen=1;
            }
        }
        if(cen==0){
            x=new nodo;
            cout<<"\n\nNombre: ";
            cin>>x->nomb;
            x->sig=q;
            r=q->ant;
            x->ant=r;
            q->ant=x;
            if(p==q){
                p=x;
            }
            else{
                r->sig=x;
            }
        }
        else cout<<"NO EXISTE EL DATO REFERENCIAL";
    }
    else cout<<"LISTA VACIA";
    return (p);
}
nodo *inserta_dd(nodo *f, char ref[]){
    nodo *q, *r,*x;
    int cen;
    if(f!=NULL){
        q=f;
        cen=0;
        while(strcmp(q->nomb,ref)!=0 and cen==0){
            if(q->ant!=NULL){
                q=q->ant;
            }
            else{
                cen=1;
            }
        }
        if(cen==0){
            x=new nodo;
            cout<<"\n\nNombre: ";
            cin>>x->nomb;
            x->ant=q;
            r=q->sig;
            x->sig=r;
            q->sig=x;
            if(f==q){
                f=q;
            }
            else{
                r->ant=x;
            }
        }
        else cout<<"NO EXISTE EL DATO REFERENCIAL";
    }
    else cout<<"LISTA VACIA";
    return (f);
}
void eliminad_p(nodo *&p, nodo*&f){
    nodo *q;
    if(p!=NULL){
        q=p;
        p=q->sig;
        if(p==f){
            f=NULL;
        }
        else{
            f->ant=NULL;
        }
        delete(q);
    }
    else cout<<"LISTA VACIA NO SE PUEDO ELIMINAR";
}
void eliminad_u(nodo *&p, nodo *&f){
    nodo *q;
    if(p!=NULL){
        q=f;
        f=f->ant;
        if(p==q){
            p=NULL;
        }
        else{
            f->sig=NULL;
        }
        delete(q);
    }
    else cout<<"LISTA VACIA NO SE PUEDE ELIMINAR";
}
void eliminad_x(nodo *&p, nodo *&f, char ref[]){
    nodo *q, *r, *s;
    int cen;
    if(p!=NULL){
        q=p;
        cen=0;
        while(strcmp(q->nomb,ref)!=0 and cen==0){
            if(q->sig!=NULL){
                q=q->sig;
            }
            else{
                cen=1;
            }
        }
        if(cen==0){
            if(p==f){
                p=NULL;
                f=NULL;
            }
            else{
                if(p==q){
                    p=p->sig;
                    p->ant=NULL;
                }
                else{
                    if(q==f){
                        f=f->ant;
                        f->sig=NULL;
                    }
                    else{
                        r=q->ant;
                        s=q->sig;
                        r->sig=s;
                        s->ant=r;
                    }
                }
            }
            delete(q);
        }
        else{
            cout<<"NO EXISTE EL DATO REFERENCIAL";
        }
    }
}
nodo *eliminad_AD(nodo *p, char ref[]){
    nodo *q, *r, *s;
    int cen;
    if(p!=NULL){
        q=p;
        cen=0;
        while(strcmp(q->nomb,ref)!=0 and cen==0){
            if(q->sig!=NULL){
                q=q->sig;
            }
            else{
                cen=1;
            }
        }
        if(cen==0){
            if(p==q){
                cout<<"NO EXISTE NODO ANTERIOR AL REFERENCIAL";
            }
            else{
                r=q->ant;
                if(p==r){
                    p=q;
                    p->ant=NULL;
                }
                else{
                    s=r->ant;
                    s->sig=q;
                    q->ant=s;
                }
                delete(r);
            }
        }
        else{
            cout<<"NO EXISTE EL DATO REFERENCIAL";
        }
    }
    else{
        cout<<"LISTA VACIA";
    }
    return (p);
}
nodo *eliminad_DD(nodo *f, char ref[]){
    nodo *q, *r, *s;
    int cen;
    if(f!=NULL){
        q=f;
        cen=0;
        while(strcmp(q->nomb,ref)!=0 and cen==0){
            if(q->ant!=NULL){
                q=q->ant;
            }
            else{
                cen=1;
            }
        }
        if(cen==0){
            if(f==q){
                cout<<"NO EXISTE NODO POSTERIOR AL REFERENCIAL";
            }
            else{
                r=q->sig;
                s=r->sig;
                q->sig=s;
                if(r==f){
                    f=q;
                }
                else
                    s->ant=q;
                delete(r);
            }
        }
        else{
            cout<<"NO EXISTE EL DATO REFERENCIAL NO SE PUEDO ELIMINAR";
        }
    }
    else{
        cout<<"LISTA VACIA NO SE PUEDO ELIMINAR ";
    }
    return (f);
}
void recorre(nodo *p){
    nodo *q;
    system("cls");
    q=p;
    cout<<"\n\n\tLISTA DE DATOS:\n";
    cout<<"\t===============";
    while(q!=NULL){
        cout<<"\n\n\t\t"<<q->nomb;
        q=q->sig;
    }
    cout<<"\n\n\t\t\t";
}