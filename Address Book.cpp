#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

// Node structure for doubly linked list
struct Node
{
    string name;
    string address;
    string email;
    string phone;
    string notes;
    Node* prev;
    Node* next;
};

class AddressBook
{
private:
    Node* head;
    Node* tail;

public:
    // Default constructor
    AddressBook()
    {
        head = NULL;
        tail = NULL;
    }

    // Function to create a new contact
    void createContact(string name, string address, string email, string phone, string notes)
    {
        Node* newContact = new Node;
        newContact->name = name;
        newContact->address = address;
        newContact->email = email;
        newContact->phone = phone;
        newContact->notes = notes;
        newContact->prev = NULL;
        newContact->next = NULL;

        if (head == NULL)
        {
            head = newContact;
            tail = newContact;
        }
        else
        {
            tail->next = newContact;
            newContact->prev = tail;
            tail = newContact;
        }
    }

    // Function to edit a contact
    void editContact(string name, string newAddress, string newEmail, string newPhone, string newNotes)
    {
        Node* current = head;
        while (current != NULL)
        {
            if (current->name == name)
            {
                current->address = newAddress;
                current->email = newEmail;
                current->phone = newPhone;
                current->notes = newNotes;
                break;
            }
            current = current->next;
        }
    }

    // Function to search for a contact
    Node* searchContact(string name)
    {
        Node* current = head;
        while (current != NULL)
        {
            if (current->name == name)
            {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
    
        // Function to delete a contact
    void deleteContact(string name)
    {
        bool found = false;
        Node* current = head;
        while (current != NULL)
        {
            if (current->name == name)
            {
                if (current->prev == NULL) //if head
                {
                    head = current->next;
                }
                else
                {
                    current->prev->next = current->next;
                }

                if (current->next == NULL) //if tail
                {
                    tail = current->prev;
                }
                else
                {
                    current->next->prev = current->prev;
                }
                delete current;
                found = true;
                break;
            }
            current = current->next;
        }
        if(!found){
            cout << "Contact Not Found in List......:(" <<endl;
            system ("pause");
        }
    }
    
    //funtion for searching data
    void search(string keyword)
	{
        bool find = false;
    Node* current = head;
    while (current != NULL)
    {
        if (current->name.find(keyword) != string::npos || current->address.find(keyword) != string::npos || current->email.find(keyword) != string::npos || current->phone.find(keyword) != string::npos || current->notes.find(keyword) != string::npos)
        {
            cout << "Name: " << current->name << endl;
            cout << "Address: " << current->address << endl;
            cout << "Email: " << current->email << endl;
            cout << "Phone: " << current->phone << endl;
            cout << "Notes: " << current->notes << endl;
            cout <<endl <<endl;
            find = true;
        }
        current = current->next;
    }
    if (!find){
        cout << "Contact Details not Found" <<endl<<endl;
    }
	}

    void printAll(){
        Node* current = head;
        int num=1;
        while(current != NULL){
            cout << "\nSr No: "<< num++  <<endl;
            cout << "Name:\t\t" << current->name <<endl;
            cout << "Address:\t" << current->address <<endl;
            cout << "Contact:\t" << current->phone<<endl;
            cout << "Email:\t\t" << current->email <<endl;
            cout << "Notes:\t\t" << current->notes <<endl;
            current = current->next;
        }
        system("pause");
    }
	
	//funtion to save data to csv
	void saveToCSV(string fileName)
	{
	    fstream outFile;
		outFile.open(fileName.c_str(), ios::out);
	    Node* current = head;
	    while (current != NULL)
	    {
	        outFile << current->name << "," << current->address << "," << current->email << "," << current->phone << "," << current->notes << endl;
	        current = current->next;
	    }
	    outFile.close();
	}
	
	//funtion to read data from csv
	void readFromCSV(string fileName)
	{
	    ifstream inFile(fileName.c_str());
	    string line;
	    while (getline(inFile, line))
	    {
	        stringstream ss(line);
	        string name, address, email, phone, notes;
	        getline(ss, name, ',');
	        getline(ss, address, ',');
	        getline(ss, email, ',');
	        getline(ss, phone, ',');
	        getline(ss, notes);
	        createContact(name, address, email, phone, notes);
	    }
	    inFile.close();
	}


};


string getValidName()
{
    string name;
    regex pattern("^[a-zA-Z]+(([',. -][a-zA-Z ])?[a-zA-Z]*)*$");
    while (true)
    {
        cout << "Enter name: ";
        getline(cin, name);
         if (regex_match(name, pattern))
        {
            break;
        }
        else
        {
            cout << "Invalid input. Name should only contain alphabetical characters." << endl;
        }
    }
    return name;
}

string getValidAddress()
{
    string address;
    while (true)
    {
        cout << "Enter address: ";
        getline(cin, address);
        if (!address.empty())
        {
            break;
        }
        else
        {
            cout << "Invalid input. Address should not be empty." << endl;
        }
    }
    return address;
}


string getValidPhoneNumber()
{
    string phone;
    while (true)
    {
        cout << "Enter phone number: ";
        cin >> phone;
        regex pattern("\\d{11}");
        if (!regex_match(phone, pattern))
        {
            cout << "Invalid input. Phone number must be a string of 11 digits length." << endl;
        }
        else
           break;
    }
    return phone;
}

string getValidEmail()
{
    string email;
    while (true)
    {
        cout << "Enter email: ";
        cin >> email;
        // Regular expression to match email address
        regex pattern("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
        if (regex_match(email, pattern))
        {
            break;
        }
        else
        {
            cout << "Invalid email address." << endl;
        }
    }
    return email;
}



string getValidNotes()
{
    string notes;
    while (true)
    {
        cout << "Enter notes: ";
        cin.ignore();
        getline(cin, notes);
        if (notes.length() < 100)
        {
            break;
        }
        else
        {
            cout << "Invalid input. Notes should be less than 100 characters." << endl;
        }
    }
    return notes;
}

char getchoice(){
    string data="";
    regex pattern("[0-9]");
    while(true){
        cout << "Enter you Choice:\t";
        getline(cin,data);
        if(regex_match(data,pattern)){
            return data[0];
        }
        cout << "Invalid Entry. Enter Valid Choice." <<endl<<endl;

    }
}

void banner(){
    cout <<endl;
     string a1 ="             _     _                     ____              _    ";
 string a2 ="    /\\      | |   | |                   |  _ \\            | |   ";
 string a3 ="   /  \\   __| | __| |_ __ ___  ___ ___  | |_) | ___   ___ | | __";
 string a4 ="  / /\\ \\ / _` |/ _` | '__/ _ \\/ __/ __| |  _ < / _ \\ / _ \\| |/ /";
 string a5 =" / ____ \\ (_| | (_| | | |  __/\\__ \\__ \\ | |_) | (_) | (_) |   < ";
 string a6 ="/_/    \\_\\__,_|\\__,_|_|  \\___||___/___/ |____/ \\___/ \\___/|_|\\_\\";
 
 cout << a1<<endl;
  cout << a2<<endl;
   cout << a3<<endl;
    cout << a4<<endl;
     cout << a5<<endl;
      cout << a6<<endl;
      cout <<endl<<endl;
}





int main()
{
    AddressBook addressBook;
    string fileName = "contacts.csv";
    addressBook.readFromCSV(fileName);
    char choice;
    while (true)
    {
    	system("cls");
        banner();
    	cout << "Enter Choice Number....." <<endl;
        cout << "\t1. Create Contact" << endl;
        cout << "\t2. Edit Contact" << endl;
        cout << "\t3. Search Contact" << endl;
        cout << "\t4. Delete Contact" << endl;
        cout << "\t5. Export to CSV" << endl;
        cout << "\t6. All Contacts" <<endl;
        cout << "\t7. Exit" << endl<<endl;
        // cout << "Enter your choice: ";
        choice=getchoice();
        system("cls");
        switch (choice)
        {
            case '1':
            {
                banner();
                cout << "Adding New Contact:" <<endl<<endl;
                string name, address, email, phone, notes;
                name=getValidName();
                address = getValidAddress();
                email  = getValidEmail();
                phone = getValidPhoneNumber();
                notes = getValidNotes();
                addressBook.createContact(name, address, email, phone, notes);
                addressBook.saveToCSV(fileName);
                cout << "Contact Added" <<endl<<endl;
                system("pause");
                break;
            }
            case '2':
            {
                banner();
                string name, address, email, phone, notes;
                cout << "Edit Contact Details"<<endl<<endl;
                name=getValidName();
                address = getValidAddress();
                email  = getValidEmail();
                phone = getValidPhoneNumber();
                notes = getValidNotes();


                Node* contact = addressBook.searchContact(name);
                if (contact != NULL)
                {
                    addressBook.editContact(name, address, email, phone, notes);
                }
                else{
                    cout << "Contact Name you want to Edit not found." <<endl;
                    cout << "Creating New contact with name " << name <<endl;
                    addressBook.createContact(name, address, email, phone, notes);

                }
                addressBook.saveToCSV(fileName);
                system("pause");
                break;
            }
            case '3':
            {
                banner();
                cout << "Search Contact Details\n\n";
                string name;
                cout << "Enter the Name or any other details to find contact info: ";
                getline(cin,name);
                addressBook.search(name);
                system("pause");
                break;
            }
            case '4':
            {
                banner();
                cout << "Delete Contact"<<endl<<endl;
                string name;
                name=getValidName();
                addressBook.deleteContact(name);
                break;
            }
            case '5':
            {
                banner();
                cout << "Enter the File Name to which you want to export all Contacts: ";
                string name = "";
                getline(cin, name);
                name = name + ".csv";
                addressBook.saveToCSV(name);
                cout << "Contacts saved to CSV" << endl;
                system("pause");
                break;
            }
            case '6':
            {
                banner();
                cout << "All contact Details:" <<endl <<endl;
                addressBook.printAll();
                break;
            }
            case '7':
            {
                return 0;
            }
            default:
            {
                banner();
                cout << "Invalid choice" << endl;
                system("pause");
                system("cls");
                break;
            }
        }
    }

}