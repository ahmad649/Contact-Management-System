using namespace std;
#include <iostream>
#include <string>
#include<fstream>

class hashtable
{
private:
    struct Node
    {
        int key = 0;
        string name = "";
        string primary_contact = "";
        string secondary_contact = "";
        string address = "";
        Node* Next;
    };
    Node* array_address[20];
public:
    hashtable()
    {
        for (int i = 0; i < 20; i++)
        {
            array_address[i] = NULL;
        }
    }

    void insert( int index_value, int key, string name, string primary_contact, string secondary_contact, string address)
    {
        Node* New_Node_ptr = new Node;
        Node* Current_ptr =array_address[index_value];

        New_Node_ptr->key = key;
        New_Node_ptr->name = name;
        New_Node_ptr->primary_contact = primary_contact;
        New_Node_ptr->secondary_contact = secondary_contact;
        New_Node_ptr->address = address;
        New_Node_ptr->Next = NULL;

        if (array_address[index_value] == NULL)
        {
            array_address[index_value] = New_Node_ptr;
            return;
        }
        while (Current_ptr->Next != NULL)
        {
            Current_ptr = Current_ptr->Next;
        }
        Current_ptr->Next = New_Node_ptr;
    }
    void search(string name,int index_value)
    {
        Node* PtrCurrent = array_address[index_value];
        cout <<endl;
        while (PtrCurrent != NULL && PtrCurrent->name!=name)
        {
            PtrCurrent = PtrCurrent->Next;
        }
        if (PtrCurrent == NULL)
        {
            cout << "\nThe name you entered does not match the database !!\n";
        }
        else
        {
                cout << "\nThe data entry you wished to find is located!!";
                cout << "\nKey = " << PtrCurrent->key;
                cout << "\nName = " << PtrCurrent->name;
                cout << "\nPrimary Contact Number = " << PtrCurrent->primary_contact;
                cout << "\nSecondary Contact Number = " << PtrCurrent->secondary_contact;
                cout << "\nAddress = " << PtrCurrent->address<<endl;
        }
    }
    void Delete(string name,int index_value)
    {
        Node* PtrCurrent = array_address[index_value];
        Node* PtrPrevious = PtrCurrent;
        while (PtrCurrent != NULL && PtrCurrent->name != name)
        {
            PtrPrevious = PtrCurrent;
            PtrCurrent = PtrCurrent->Next;
        }
        if (PtrCurrent == NULL)
        {
            cout << "\nThe name you entered does not match the database !!\n";
            return;
        }
        if (PtrCurrent == array_address[index_value])
        {
            array_address[index_value] = array_address[index_value]->Next;
        }
        else
        {
            PtrPrevious->Next = PtrCurrent->Next;
        }
        delete PtrCurrent;
        cout << "\nThe data corresponding to the name you entered is successfully deleted from the database !!\n";
    }
};
long hashing_function(string input)
{
    long key;
    key = hash<string>{}(input);
    if (key < 0)
    {
        key = -key;
    }
    return key;
}

int mapping_function(long key)
{
    return key % 20;
}
void menu()
{
    cout << "CHOOSE AN OPTION (Enter the corresponding number to the option you want to select)\n\n";
    cout << "1. Insert Data\n";
    cout << "2. Search Data\n";
    cout << "3. Delete Data\n";
    cout << "4. Exit\n";
}
int main()
{
    system("Color 0B");
    cout << "                                              CONTACT MANAGEMENT SYSTEM\n";
    int key = 0;
    string name = "";
    string primary_contact = "";
    string secondary_contact = "";
    string address = "";

    hashtable instance;
    ifstream fin;
    fin.open("sample_data.txt");

    if (!fin)
    {
        cout << "File does not exist !! Failed to open the file.\n";
    }
    long code;
    int index_value;
    for (int i = 0; i < 3; i++)
    {
        fin >> key;
        fin >> name;
        fin >> primary_contact;
        fin >> secondary_contact;
        fin >> address;
        code = hashing_function(name);
        index_value = mapping_function(code); 
        instance.insert(index_value, key, name, primary_contact, secondary_contact, address);
    }
    cout << "The data from the file is successfully added to the hashtable list !!\n\n" << endl;
    int choice;
    do {
        menu();
        cin >> choice;
        while (!(choice == 1 || choice == 2 || choice == 3 || choice == 4))
        {
            menu();
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            cout << "\nEnter the key of the data entry : ";
            cin >> key;
            cout << "\nEnter the name of the data entry : ";
            cin >> name;
            cout << "\nEnter the primary contact number of the data entry : ";
            cin >> primary_contact;
            cout << "\nEnter the secondary contact number of the data entry : ";
            cin >> secondary_contact;
            cout << "\nEnter the address of the data entry : ";
            cin >> address;
            code = hashing_function(name);
            index_value = mapping_function(code);
            instance.insert(index_value, key, name, primary_contact, secondary_contact, address);
            cout << "\nThe data is successfully added to the hashtable list !!\n\n" << endl;
            break;
        case 2:
            cout << "\nPlease enter the name of the person whose data entry you want to search : ";
            cin >> name;
            code = hashing_function(name);
            index_value = mapping_function(code);
            instance.search(name, index_value);
            break;
        case 3:
            cout << "\nPlease enter the name of the person whose data entry you want to delete : ";
            cin >> name;
            code = hashing_function(name);
            index_value = mapping_function(code);
            instance.Delete(name, index_value);
            break;
        case 4:
            return 0;
            break;
        }
    } while (choice != 4);
}