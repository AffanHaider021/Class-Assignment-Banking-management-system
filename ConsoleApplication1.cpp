#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
    int accountID;
    string holderName;
    string accountType;
    double balance;

public:
    Account()
    {
        accountID = 0;
        holderName = "";
        accountType = "";
        balance = 0;
    }

    Account(int id, string name, string type, double amount)
    {
        accountID = id;
        holderName = name;
        accountType = type;
        balance = amount;
    }

    Account(const Account& a)
    {
        accountID = a.accountID;
        holderName = a.holderName;
        accountType = a.accountType;
        balance = a.balance;
    }

    void setAccountID(int id)
    {
        accountID = id;
    }

    void setHolderName(string name)
    {
        holderName = name;
    }

    void setAccountType(string type)
    {
        accountType = type;
    }

    void setBalance(double amount)
    {
        balance = amount;
    }

    int getAccountID()
    {
        return accountID;
    }

    string getHolderName()
    {
        return holderName;
    }

    string getAccountType()
    {
        return accountType;
    }

    double getBalance()
    {
        return balance;
    }

    void inputData()
    {
        cout << "Enter Account ID: ";
        cin >> accountID;

        cin.ignore();

        cout << "Enter Account Holder Name: ";
        getline(cin, holderName);

        cout << "Enter Account Type (Savings/Current): ";
        getline(cin, accountType);

        cout << "Enter Balance: ";
        cin >> balance;
    }

    void displayData()
    {
        cout << "\nAccount ID: " << accountID << endl;
        cout << "Account Holder: " << holderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
        cout << "-----------------------------" << endl;
    }

    void updateData()
    {
        int choice;

        cout << "\n1. Update Account Holder Name" << endl;
        cout << "2. Update Account Type" << endl;
        cout << "3. Update Balance" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter New Account Holder Name: ";
            getline(cin, holderName);
            cout << "Name Updated Successfully!" << endl;
            break;

        case 2:
            cout << "Enter New Account Type: ";
            getline(cin, accountType);
            cout << "Account Type Updated Successfully!" << endl;
            break;

        case 3:
            cout << "Enter New Balance: ";
            cin >> balance;
            cout << "Balance Updated Successfully!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }
    }
};

int main()
{
    Account accounts[100];
    int count = 0;
    int choice;
    int id;
    int found;

    do
    {
        cout << "\n===== BANKING MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add Account Data" << endl;
        cout << "2. View Records" << endl;
        cout << "3. Search Record" << endl;
        cout << "4. Update Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (count < 100)
            {
                Account a;
                a.inputData();

                found = 0;

                for (int i = 0; i < count; i++)
                {
                    if (accounts[i].getAccountID() == a.getAccountID())
                    {
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    accounts[count] = a;
                    count++;
                    cout << "Account Added Successfully!" << endl;
                }
                else
                {
                    cout << "Account ID Already Exists!" << endl;
                }
            }
            else
            {
                cout << "Account Storage Is Full!" << endl;
            }

            break;
        }

        case 2:
        {
            if (count == 0)
            {
                cout << "No Records Available!" << endl;
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    accounts[i].displayData();
                }
            }

            break;
        }

        case 3:
        {
            cout << "Enter Account ID to Search: ";
            cin >> id;

            found = 0;

            for (int i = 0; i < count; i++)
            {
                if (accounts[i].getAccountID() == id)
                {
                    accounts[i].displayData();
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                cout << "Record Not Found!" << endl;
            }

            break;
        }

        case 4:
        {
            cout << "Enter Account ID to Update: ";
            cin >> id;

            found = 0;

            for (int i = 0; i < count; i++)
            {
                if (accounts[i].getAccountID() == id)
                {
                    accounts[i].updateData();
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                cout << "Record Not Found!" << endl;
            }

            break;
        }

        case 5:
            cout << "Thank You for Using Banking Management System!" << endl;
            break;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 5);

}