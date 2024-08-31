#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_ROOMS = 100;

class HOTEL {
private:
    struct Customer {
        int room_no;
        string name;
        string address;
        string phone;
        long days;
        long cost;
        string rtype;
        long pay;
    };

    Customer customers[MAX_ROOMS];

    int check(int);

public:
    void main_menu();
    void add();
    void display();
    void rooms();
    void edit();
    void modify();
    void modify_name(int);
    void modify_address(int);
    void modify_phone(int);
    void modify_days(int);
    void delete_rec();
    void restaurant();
    void breakfast(int);
    void lunch(int);
    void dinner(int);
};

void HOTEL::main_menu() {
    int choice;
    while (choice != 6) {
        system("clear");
        cout << "\n\t\t\t\t *************";
        cout << "\n\t\t\t\t *THE HOTEL*";
        cout << "\n\t\t\t\t *************";
        cout << "\n\t\t\t\t * MAIN MENU *";
        cout << "\n\t\t\t\t *************";
        cout << "\n\n\n\t\t\t\t1. Book A Room";
        cout << "\n\t\t\t\t2. Customer Information";
        cout << "\n\t\t\t\t3. Rooms Allotted";
        cout << "\n\t\t\t\t4. Edit Customer Details";
        cout << "\n\t\t\t\t5. Order Food from Restaurant";
        cout << "\n\t\t\t\t6. Exit";
        cout << "\n\n\t\t\t\tEnter Your Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                rooms();
                break;
            case 4:
                edit();
                break;
            case 5:
                restaurant();
                break;
            case 6:
                return;
            default:
                cout << "\n\n\t\t\tWrong choice.";
                cout << "\n\t\t\tPress any key to continue.";
                getchar();
                break;
        }
    }
}
void HOTEL::add() {
    system("clear");
    int r, flag;
    
    cout << "\n\t\t\t ";
    cout << "\n\t\t\t | Rooms  |   Room Type  |";
    cout << "\n\t\t\t  -----------------------";
    cout << "\n\t\t\t |   1-50 |    Deluxe    |";
    cout << "\n\t\t\t |  51-80 |   Executive  |";
    cout << "\n\t\t\t | 81-100 | Presidential |";
    cout << "\n\t\t\t    ----------------------+";
    
    cout << "\n\n ENTER CUSTOMER DETAILS";
    cout << "\n ----------------------";
    
    cout << "\n\n Room Number: ";
    cin >> r;

    flag = check(r);

    if (flag == 1)
        cout << "\n Sorry, Room is already booked.\n";
    else {
        if (flag == 2)
            cout << "\n Sorry, Room does not exist.\n";
        else {
            customers[r - 1].room_no = r;

            cout << "\n Name: ";
            cin >> customers[r - 1].name;

            cout << " Address: ";
            cin >> customers[r - 1].address;

            cout << " Phone Number: ";
            cin.ignore(); // Ignore the newline character left in the buffer
            getline(cin, customers[r - 1].phone); // Read the entire line

            cout << " Number of Days: ";
            cin >> customers[r - 1].days;

            if (r >= 1 && r <= 50) {
                customers[r - 1].rtype = "Deluxe";
                customers[r - 1].cost = customers[r - 1].days * 10000;
            } else if (r >= 51 && r <= 80) {
                customers[r - 1].rtype = "Executive";
                customers[r - 1].cost = customers[r - 1].days * 12500;
            } else if (r >= 81 && r <= 100) {
                customers[r - 1].rtype = "Presidential";
                customers[r - 1].cost = customers[r - 1].days * 15000;
            }

            cout << "\n Room has been booked.";
        }
    }
    
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}


void HOTEL::display() {
    system("clear");
    int r, flag;
    cout << "\n Enter Room Number: ";
    cin >> r;
    flag = check(r);
    if (flag == 0)
        cout << "\n Room is Vacant.";
    else {
        system("clear");
        cout << "\n Customer Details";
        cout << "\n ----------------";
        cout << "\n\n Room Number: " << customers[r - 1].room_no;
        cout << "\n Name: " << customers[r - 1].name;
        cout << "\n Address: " << customers[r - 1].address;
        cout << "\n Phone Number: " << customers[r - 1].phone;
        cout << "\n Staying for " << customers[r - 1].days << " days.";
        cout << "\n Room Type: " << customers[r - 1].rtype;
        cout << "\n Total cost of stay: " << customers[r - 1].cost;
    }
    cout << "\n\n Press any key to continue.";
    getchar();
    getchar();
}

void HOTEL::rooms() {
    system("clear");
    const char separator = ' ';
    const int NoWidth = 8;
    const int GuestWidth = 17;
    const int AddressWidth = 16;
    const int RoomWidth = 13;
    const int ContactNoWidth = 13;

    cout << "\n\t\t\t    LIST OF ROOMS ALLOTTED";
    cout << "\n\t\t\t   -----------------------";
    cout << "\n +---------+------------------+-----------------+--------------+--------------+";
    cout << "\n | Room No.|    Guest Name    |      Address    |   Room Type  |  Contact No. |";
    cout << "\n +---------+------------------+-----------------+--------------+--------------+";

    for (int i = 0; i < MAX_ROOMS; ++i) {
        if (customers[i].room_no != 0) {
            cout << "\n |" << setw(NoWidth) << setfill(separator) << customers[i].room_no << " |";
            cout << setw(GuestWidth) << setfill(separator) << customers[i].name << " |";
            cout << setw(AddressWidth) << setfill(separator) << customers[i].address << " |";
            cout << setw(RoomWidth) << setfill(separator) << customers[i].rtype << " |";
            cout << setw(ContactNoWidth) << setfill(separator) << customers[i].phone << " |";
        }
    }

    cout << "\n +---------+------------------+-----------------+--------------+--------------+";
    cout << "\n\n\n\t\t\tPress any key to continue.";
    getchar();
    getchar();
}

void HOTEL::edit() {
    system("clear");
    int choice, r;
    cout << "\n EDIT MENU";
    cout << "\n ---------";
    cout << "\n\n 1. Modify Customer Information.";
    cout << "\n 2. Customer Check Out.";
    cout << "\n Enter your choice: ";
    cin >> choice;
    system("clear");
    switch (choice) {
        case 1:
            modify();
            break;
        case 2:
            delete_rec();
            break;
        default:
            cout << "\n Wrong Choice.";
            break;
    }
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}

int HOTEL::check(int r) {
    if (r < 1 || r > MAX_ROOMS) {
        return 2; // Room does not exist
    }

    if (customers[r - 1].room_no != 0) {
        return 1; // Room is already booked
    }

    return 0; // Room is vacant
}

void HOTEL::modify() {
    system("clear");
    int ch, r;
    cout << "\n MODIFY MENU";
    cout << "\n -----------";
    cout << "\n\n\n 1. Modify Name";
    cout << "\n 2. Modify Address";
    cout << "\n 3. Modify Phone Number";
    cout << "\n 4. Modify Number of Days of Stay";
    cout << "\n Enter Your Choice: ";
    cin >> ch;
    system("clear");
    cout << "\n Enter Room Number: ";
    cin >> r;
    switch (ch) {
        case 1:
            modify_name(r);
            break;
        case 2:
            modify_address(r);
            break;
        case 3:
            modify_phone(r);
            break;
        case 4:
            modify_days(r);
            break;
        default:
            cout << "\n Wrong Choice";
            break;
    }
}

void HOTEL::modify_name(int r) {
    long pos;
    int flag = 0;
    for (int i = 0; i < MAX_ROOMS; ++i) {
        if (customers[i].room_no == r) {
            cout << "\n Enter New Name: ";
            cin >> customers[i].name;
            cout << "\n Customer Name has been modified.";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "\n Sorry, Room is vacant.";
    getchar();
    getchar();
}

void HOTEL::modify_address(int r) {
    long pos;
    int flag = 0;
    for (int i = 0; i < MAX_ROOMS; ++i) {
        if (customers[i].room_no == r) {
            cout << "\n Enter New Address: ";
            cin >> customers[i].address;
            cout << "\n Customer Address has been modified.";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "\n Sorry, Room is vacant.";
    getchar();
    getchar();
}

void HOTEL::modify_phone(int r) {
    long pos;
    int flag = 0;
    for (int i = 0; i < MAX_ROOMS; ++i) {
        if (customers[i].room_no == r) {
            cout << "\n Enter New Phone Number: ";
            cin >> customers[i].phone;
            cout << "\n Customer Phone Number has been modified.";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "\n Sorry, Room is vacant.";
    getchar();
    getchar();
}

void HOTEL::modify_days(int r) {
    long pos;
    int flag = 0;
    for (int i = 0; i < MAX_ROOMS; ++i) {
        if (customers[i].room_no == r) {
            cout << " Enter New Number of Days of Stay: ";
            cin >> customers[i].days;
            if (r >= 1 && r <= 50) {
                customers[i].rtype = "Deluxe";
                customers[i].cost = customers[i].days * 10000;
            } else if (r >= 51 && r <= 80) {
                customers[i].rtype = "Executive";
                customers[i].cost = customers[i].days * 12500;
            } else if (r >= 81 && r <= 100) {
                customers[i].rtype = "Presidential";
                customers[i].cost = customers[i].days * 15000;
            }
            cout << "\n Customer information is modified.";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "\n Sorry, Room is Vacant.";
    getchar();
    getchar();
}

void HOTEL::delete_rec() {
    int r, flag = 0;
    char ch;
    cout << "\n Enter Room Number: ";
    cin >> r;
    for (int i = 0; i < MAX_ROOMS; ++i) {
        if (customers[i].room_no == r) {
            cout << "\n Name: " << customers[i].name;
            cout << "\n Address: " << customers[i].address;
            cout << "\n Phone Number: " << customers[i].phone;
            cout << "\n Room Type: " << customers[i].rtype;
            cout << "\n Your total bill is: Rs. " << customers[i].cost;
            cout << "\n\n Do you want to check out this customer(y/n): ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y') {
                customers[i].room_no = 0;
                customers[i].name = "";
                customers[i].address = "";
                customers[i].phone = "";
                customers[i].days = 0;
                customers[i].cost = 0;
                customers[i].rtype = "";
                customers[i].pay = 0;
                cout << "\n Customer has been checked out.";
            } else {
                cout << "\n Check out process aborted.";
            }
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "\n Sorry, Room is vacant.";
    getchar();
    getchar();
}

void HOTEL::restaurant() {
    system("clear");
    int choice, r;
    cout << "\n RESTAURANT MENU";
    cout << "\n ---------------";
    cout << "\n\n 1. Breakfast";
    cout << "\n 2. Lunch";
    cout << "\n 3. Dinner";
    cout << "\n Enter your choice: ";
    cin >> choice;
    system("clear");
    cout << "\n Enter Room Number: ";
    cin >> r;
    switch (choice) {
        case 1:
            breakfast(r);
            break;
        case 2:
            lunch(r);
            break;
        case 3:
            dinner(r);
            break;
        default:
            cout << "\n Wrong Choice.";
            break;
    }
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
}

void HOTEL::breakfast(int r) {
    cout << "\n BREAKFAST MENU";
    cout << "\n ---------------";
    cout << "\n 1. Sandwich - Rs. 50";
    cout << "\n 2. Pancakes - Rs. 75";
    cout << "\n 3. Omelette - Rs. 60";
    cout << "\n 4. Tea/Coffee - Rs. 10";
    cout << "\n Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            customers[r - 1].pay += 50;
            break;
        case 2:
            customers[r - 1].pay += 75;
            break;
        case 3:
            customers[r - 1].pay += 60;
            break;
        case 4:
            customers[r - 1].pay += 10;
            break;
        default:
            cout << "\n Wrong Choice.";
            break;
    }
    cout << "\n Breakfast order placed for Room " << r;
}

void HOTEL::lunch(int r) {
    cout << "\n LUNCH MENU";
    cout << "\n -----------";
    cout << "\n 1. Burger - Rs. 70";
    cout << "\n 2. Pizza - Rs. 120";
    cout << "\n 3. Pasta - Rs. 90";
    cout << "\n 4. Soft Drink - Rs. 25";
    cout << "\n Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            customers[r - 1].pay += 70;
            break;
        case 2:
            customers[r - 1].pay += 120;
            break;
        case 3:
            customers[r - 1].pay += 90;
            break;
        case 4:
            customers[r - 1].pay += 25;
            break;
        default:
            cout << "\n Wrong Choice.";
            break;
    }
    cout << "\n Lunch order placed for Room " << r;
}

void HOTEL::dinner(int r) {
    cout << "\n DINNER MENU";
    cout << "\n ------------";
    cout << "\n 1. Fried Rice - Rs. 100";
    cout << "\n 2. Chicken Curry - Rs. 150";
    cout << "\n 3. Veg Biryani - Rs. 120";
    cout << "\n 4. Ice Cream - Rs. 30";
    cout << "\n Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            customers[r - 1].pay += 100;
            break;
        case 2:
            customers[r - 1].pay += 150;
            break;
        case 3:
            customers[r - 1].pay += 120;
            break;
        case 4:
            customers[r - 1].pay += 30;
            break;
        default:
            cout << "\n Wrong Choice.";
            break;
    }
    cout << "\n Dinner order placed for Room " << r;
}

int main() {
    HOTEL hotel;
    hotel.main_menu();
    return 0;
}