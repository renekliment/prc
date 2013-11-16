#ifndef _LIST_
#define _LIST_

typedef int T;

// polozka seznamu
struct ListItem
{
  T item;
  struct ListItem *next;
};

typedef struct ListItem ListItem;

// vlastni seznam, kazda instance bude mit vlastni strukturu
typedef struct
{
  ListItem *first;
  ListItem *last;
  int length;
} List;

// inicializuj seznam, vse ve strukture list bude 0 ci NULL
// v pripade, ze list je NULL, vrati -1, jinak 0
int initializeList(List *list);

// vrati delku seznamu
// v pripade, ze list je NULL, vrati -1, jinak 0
int getLength(List *list);

//  pridani polozky seznamu na konec
// v pripade, ze list je NULL, vrati -1, jinak 0
int addItem(List *list, T* item);

// vrat polozku na dane pozici
// v pripade, ze list je NULL nebo ze pos je mimo rozsah, vrati NULL
T* getItem(List *list, int pos);

// vrati ukazatel na prvni polozku seznamu, ktera ma predanou hodnotu
// v pripade, ze list je NULL nebo item neni v seznamu, vrati NULL
T* findFirst(List *list, T* item);

// smaze prvek na pozici v seznamu
// v pripade, ze list je NULL nebo ze pos je mimo rozsah, vrati -1, jinak 0
int delItemP(List *list, int pos);


// smaze cely seznam a uvede ho do stavu inicializace (vse bude NULL nebo 0)
// neprovede nic, pokud je list NULL
void delAll(List *list);

#endif
