#include<iostream>
#include"funciones.h"
using namespace std;

int main(){
    char codigo[10];
    nodo *p=NULL, *f=NULL;
    int op;
    do{
        system("cls");
        cout<<"\nLISTAS DOBLEMENTE ENLAZADAS";
        cout<<"\n========================";
        cout<<"\n\n1. Crear lista por el inicio";
        cout<<"\n\n2. Crear lista por el final";
        cout<<"\n\n3. Insertar nodo por el inicio";
        cout<<"\n\n4. Insertar nodo por el final";
        cout<<"\n\n5. Insertar antes de:";
        cout<<"\n\n6. Insertar despues de:";
        cout<<"\n\n7. Eliminar el primer nodo";
        cout<<"\n\n8. Eliminar el ultimo nodo";
        cout<<"\n\n9. Eliminar un nodo en especifico:";
        cout<<"\n\n10. Eliminar el nodo anterior a ";
        cout<<"\n\n11. Eliminar el nodo posterior a ";
        cout<<"\n\n12. Mostrar lista";
        cout<<"\n\n13. Salir";
        cout<<"\n\n\t\t\tOpcion: ";
        cin>>op;
        switch(op){
            case 1:
                system("cls");
                cread_i(p, f);
                break;
            case 2:
                system("cls");
                cread_f(p, f);
                break;
            case 3:
                system("cls");
                insertad_i(p, f);
                break;
            case 4:
                system("cls");
                insertad_f(p, f);
                break;
            case 5:
                system("cls");
                cout<<"\n\nInsertar antes de: ";
                cin>>codigo;
                p=inserta_ad(p,codigo);
                break;
            case 6:
                system("cls");
                cout<<"\n\nInsertar despues de: ";
                cin>>codigo;
                f=inserta_dd(f,codigo);
                break;
            case 7:
                system("cls");
                eliminad_p(p,f);
                break;
            case 8:
                system("cls");
                eliminad_u(p,f);
                break;
            case 9:
                system("cls");
                cout<<"\n\nEliminar nodo: ";
                cin>>codigo;
                eliminad_x(p,f,codigo);
                break;
            case 10:
                system("cls");
                cout<<"\n\nEliminar nodo anterior a: ";
                cin>>codigo;
                p=eliminad_AD(p,codigo);
                break;
            case 11:
                system("cls");
                cout<<"\n\nEliminar nodo posterior a: ";
                cin>>codigo;
                f=eliminad_DD(f,codigo);
                break;
            case 12:
                system("cls");
                recorre(p);
                system("pause");
                break;
            case 13:
                system("cls");
                cout<<"\n\nSaliendo del programa...";
                system("pause");
                break;
        }
    }while(op>0 && op<13);
    return 0;
}