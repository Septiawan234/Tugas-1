#include<iostream>
#include<cstdlib>

using namespace std;
struct node
{
    int data;
    struct node* link;
};
node* root = NULL;

/*Fungsi untuk membuat node baru menggunakan alokasi dinamis*/
node* getnode(void)
{
    node* ptr;
    ptr = new node;
    return (ptr);
}

/*Fungsi untuk membebaskan sebuah node*/
void freenode(node* ptr)
{
    delete(ptr);
}

/*Fungsi untuk menambahkan node di awal list*/
void AddAtBegin(void)
{
    node* temp;
    temp = getnode();
    cout<<"Masukkan data yang ingin dimasukkan :\n";
    cin>>temp->data;
    temp->link = root;
    root = temp;
    cout<<"Elemen berhasil dimasukkan!!!\n";
}

/*Fungsi untuk mencari lokasi node setelah kita ingin menyisipkan elemen*/
node* nodeforInsertion(int data)
{
    node* loc;
    node* save;
    node* ptr;
    save = root;
    ptr = root->link;
    if(root==NULL)
    {
        loc = NULL;
        return loc;
    }
    if(data<root->data)
    {
        loc = NULL;
        return loc;
    }
    while(ptr!=NULL)
    {
        if(data<ptr->data)
        {
            loc = save;
            return loc;
        }
        save = ptr;
        ptr = ptr->link;
    }
    loc = save;
    return loc;
}

/*Fungsi untuk menambahkan node di antara dua node*/
void AddBetween(void)
{
    node* temp;
    node* loc;
    temp = getnode();
    cout<<"Masukkan data yang ingin dimasukkan :\n";
    cin>>temp->data;
    loc = nodeforInsertion(temp->data);
    if(loc==NULL)
    {
        temp->link = root;
        root = temp;
    }
    else
    {
        temp->link = loc->link;
        loc->link = temp;
    }
    cout<<"Elemen berhasil dimasukkan!!!\n";
}

/*Fungsi untuk mencari lokasi node yang ingin kita hapus dan lokasi node sebelumnya*/
void nodeforDeletion(int ele,node** loc,node** locp)
{
    node* save;
    node* ptr;
    save = root;
    ptr = root->link;
    if(root==NULL)
    {
        *loc = NULL;
        *locp = NULL;
        return;
    }
    if(ele==root->data)
    {
        *loc = root;
        *locp = NULL;
        return;
    }
    while(ptr!=NULL)
    {
        if(ele==ptr->data)
        {
            *loc = ptr;
            *locp = save;
            return;
        }
        save = ptr;
        ptr = ptr->link;
    }
    *loc = NULL;
    return;
}

/*Fungsi untuk menghapus node*/
void deleteNode(node* loc,node* locp)
{
    if(loc==NULL)
    {
         cout<<"Elemen tidak ditemukan untuk dihapus\n";
         return;
    }
    if(locp==NULL)
    {
        root=root->link;
        freenode(loc);
        cout<<"Item berhasil dihapus!!!\n";
    }
    else
    {
        locp->link = loc->link;
        freenode(loc);
        cout<<"Item berhasil dihapus!!!\n";
    }
}

/*Fungsi untuk menampilkan daftar dengan arah maju*/
void display(void)
{
    node* temp = root;
    if(temp==NULL)
    {
        cout<<"Tidak ada elemen untuk ditampilkan\n";
    }
    else
    {
         while(temp!=NULL)
         {
            cout<<temp->data;
            temp = temp->link;
            if(temp!=NULL)
            {
                cout<<"-->";
            }
         }
         cout<<endl;
    }
}

/*Fungsi untuk mencari panjang list*/
int length(void)
{
    int len = 0;
    node* temp = root;
    while(temp!=NULL)
    {
        len++;
        temp = temp->link;
    }
    return(len);
}

/*Fungsi untuk mencari elemen dalam daftar*/
node* search(int item)
{
    node* loc;
    node* ptr = root;
    while(ptr!=NULL)
    {
        if(ptr->data==item)
        {
            return(ptr);
        }
        else
        {
            ptr = ptr->link;
        }
    }
    return(NULL);
}

/*Fungsi untuk membalik daftar*/
void reverse()
{
    node *current = root;
    node *prev = NULL, *link = NULL;
    while (current != NULL)
    {
        // Simpan selanjutnya
        link = current->link;
        // Membalikkan node pointer saat ini
        current->link = prev;
        // Pindahkan pointer satu posisi ke depan.
        prev = current;
        current = link;
    }
    root = prev;
    cout<<"Daftar berhasil dibalik!!!\n";
}

int main()
{
    int ch;
    while(1)
    {
        cout<<"Tekan 1 untuk menyisipkan node di awal\n";
        cout<<"Tekan 2 untuk menyisipkan node di akhir\n";
        cout<<"Tekan 3 untuk menghapus node\n";
        cout<<"Tekan 4 untuk menampilkan daftar\n";
        cout<<"Tekan 5 untuk mencari panjang daftar\n";
        cout<<"Tekan 6 untuk mencari elemen dalam daftar\n";
        cout<<"Tekan 7 untuk membalik daftar\n";
        cout<<"Tekan 8 untuk keluar dari program\n\n";
        cout<<"Masukkan pilihanmu :";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
            case 1:
                AddAtBegin();
                cout<<endl;
                break;
            case 2:
                AddBetween();
                cout<<endl;
                break;
            case 3:
                node* loc;
                node* locp;
                int item;
                cout<<"Masukkan data yang ingin dihapus : \n";
                cin>>item;
                nodeforDeletion(item,&loc,&locp);
                deleteNode(loc,locp);
                cout<<endl;
                break;
            case 4:
                display();
                cout<<endl;
                break;
            case 5:
                int len;
                len = length();
                cout<<"Ukuran daftar tertaut adalah: "<<len<<endl;
                cout<<endl;
                break;
            case 6:
                int finditem;
                cout<<"Masukkan elemen yang ingin Anda cari : \n";
                cin>>finditem;
                node* location;
                location = search(finditem);
                if(location==NULL)
                {
                    cout<<"Pencarian tidak berhasil, elemen tidak ditemukan\n";
                }
                else
                {
                    cout<<"Pencarian berhasil, elemen ditemukan\n";
                }
                cout<<endl;
                break;
            case 7:
                reverse();
                cout<<endl;
                break;
            case 8:
                exit(0);
            default:
                cout<<"Silakan masukkan pilihan yang benar\n";
                cout<<endl;
        }
    }
    return 0;
}
