#include <iostream>

class node{
public:
    int num;
    std::string name;
    int age;
    bool isVip;
    node* next;
};

class LinkedList{
public:
    node* head;
    int count;

    LinkedList(){
        head = nullptr;
        count = 0;
    }

    ~LinkedList(){
        node* current = head;
        while (current != nullptr){
            node* temp = current;
            current = current -> next;
            delete temp;
        }
    }

    void addNode(int num, std::string name, int age, bool isVip){
        node* newNode= new node();
        newNode->num = num;
        newNode->name= name;
        newNode->age= age;
        newNode->isVip= isVip;
        newNode->next= nullptr;

        if (head== nullptr){
            head= newNode;
        }else{
            node* temp= head;
            while (temp->next != nullptr){
                temp= temp->next;
            }
            temp->next= newNode;
        }
    }

    void addCus(){
        
        int num;
        std::string name;
        int age;
        bool isVip;

        std::cout<<"customer number: ";
        std::cin>>num;
        std::cout<<"enter name of customer: ";
        std::cin>>name;
        std::cout<<"enter age of customer: ";
        std::cin>>age;
        std::cout<<"enter 1 if vip customer else enter 0: ";
        std::cin>>isVip;

        addNode(num,name, age, isVip);
        count++;
    }

    void delCus(int num){

        //case where no customers are in the linked list
        if (head == nullptr){
            std::cout<< "We cannot Remove any customers since all rooms are vacant"<< std::endl;
            return;
        }

        //case where customer at first node is to be deleted
        if (head->num == num){
            node* nodetoDel = head;
            head = head ->next;
            delete nodetoDel;
            std::cout<<"Customer with num "<< num <<" deleted"<<std::endl;
            return;
        }

        node* current = head;
        //traverses through list till any one of the condition is unfulfilled
        while (current->next != nullptr && current->next->num != num){ 
            current = current-> next;
        }

        //handles condition where the node to be deleted is not found and the whole list is traversed
        if(current->next==nullptr){
            std::cout << "Customer with num "<< num <<" not found."<<std::endl;
            return;
        }

        //deletes the node whose num is being input 
        node* nodetoDel = current->next;
        current->next = current->next->next;
        delete nodetoDel;
        std::cout<<"Customer with num "<< num <<" deleted"<<std::endl;
    }

    void print(){
        node*temp= head;
        while (temp != nullptr){
            std::cout<<"Number: "<<temp->num<<" Name: "<<temp->name
            << " Age: "<< temp->age<< " VIP status: "<<temp->isVip<<std::endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;

    while (true) {
        std::cout << "1. Add customer" << std::endl;
        std::cout << "2. Delete customer" << std::endl;
        std::cout << "3. Display customers" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                list.addCus();
                break;
            case 2: {
                int num;
                std::cout << "Enter number of customer to delete: ";
                std::cin >> num;
                list.delCus(num);
                break;
            }
            case 3:
                list.print();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
