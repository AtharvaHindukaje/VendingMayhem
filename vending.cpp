#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

struct node
{
    int quantity;
    int price;
    string productName;
    node *next;
} *book, *map, *pencil, *eraser, *calculator;

int depart;
string item[10];
int items = 0;
int total = 0;
int grandTotal = 0;
int change = 0;
int amount = 0;

node *insertAtEnd(int data, string name, node *Node, int quantity)
{
    struct node *ptr, *tempnode;
    tempnode = new node();
    tempnode->price = data;
    tempnode->productName = name;
    ptr = Node;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = tempnode;
    tempnode->quantity = quantity;
    tempnode->next = NULL;
    return Node;
}

node *Delete(node *Node)
{
    node *tempNode = Node;
    Node = Node->next;
    free(tempNode);
    return Node;
}

node *Remove(node *Node)
{
    if (Node->quantity < 1)
    {
        cout << " No Items Available" << endl;
        return Node;
    }
    Node = Delete(Node);

    item[items] = Node->productName;
    items++;
    total += Node->price;
    cout << "  " << Node->productName << " Added In Your Cart Successfully!" << endl;
    return Node;
}

node *createNode(int size, string name, int price, node *Node)
{
    struct node *temp;
    temp = new node();
    for (int i = 0; i <= size; i++)
    {
        if (Node == NULL)
        {
            temp->productName = name;
            temp->price = price;
            temp->quantity = size;
            temp->next = NULL;
            Node = temp;
        }
        else
        {
            --size;
            Node = insertAtEnd(price, name, Node, size);
        }
    }
    return Node;
}

node *adminAdd(string name, int price, node *Node, int size)
{
    Node = createNode(size, name, price, Node);
    return Node;
}

// Coin Change problem
vector<int> denominations = {1, 5, 10, 20, 50}; 

vector<int> makeChange(int amountToChange)
{
    vector<int> dp(amountToChange + 1, INT_MAX);                                         
    dp[0] = 0;                                                                           
    vector<vector<int>> notes(amountToChange + 1, vector<int>(denominations.size(), 0)); 

    for (int i = 1; i <= amountToChange; ++i)
    {
        for (size_t j = 0; j < denominations.size(); ++j)
        {
            if (denominations[j] <= i && dp[i - denominations[j]] + 1 < dp[i])
            {
                dp[i] = dp[i - denominations[j]] + 1;
                notes[i] = notes[i - denominations[j]];
                notes[i][j]++;
            }
        }
    }
    return notes[amountToChange];
}

void printMinimumNotes(int amount)
{
    vector<int> change = makeChange(amount);
    cout << " Receiveables: " << endl;
    for (int i = 0; i < denominations.size(); ++i)
    {
        if (change[i] > 0)
        {
            if (change[i] == 1)
            {
                cout << "  Coins of Rs " << denominations[i] << " Qty: " << change[i] << endl;
            }
            else
            {
                cout << "  Notes of Rs " << denominations[i] << " Qty: " << change[i] << endl;
            }
        }
    }
}

void calculateChange(int price)
{
amountToBuy:
    int availableAmt;
    cout << " Enter Amount Available With You: ";
    cin >> availableAmt;
    if (availableAmt < total)
    {
        cout << " Amount Less Than Bill" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto amountToBuy;
    }
    else if (availableAmt > total)
    {
        cout << endl;
        change = availableAmt - total;
        cout << " Your change is: " << change << endl;
        printMinimumNotes(change);
        cout << " Thank You for shopping with us!" << endl;
    }
}

void Traverse()
{
    cout << "===================================\n";
    cout << "  S.No  Product  Price  Quantity" << endl;
    cout << "===================================\n";

    if (book->quantity < 1)
    {
        cout << " Book Not available" << endl;
    }
    else
    {
        cout << "   1"
             << "\t" << book->productName << "\t \t" << book->price << "\t \t" << book->quantity;
    }
    cout << endl;
    if (map->quantity < 1)
    {
        cout << map->productName << " Not Available" << endl;
    }
    else
    {
        cout << "   2"
             << "\t" << map->productName << "  \t   \t" << map->price << "\t \t" << map->quantity;
    }
    cout << endl;
    if (pencil->quantity < 1)
    {
        cout << pencil->productName << "Not Available" << endl;
    }
    else
    {
        cout << "   3"
             << "\t" << pencil->productName << "\t \t" << pencil->price << "\t \t" << pencil->quantity;
    }
    cout << endl;
    if (eraser->quantity < 1)
    {
        cout << " Eraser Not Available" << endl;
    }
    else
    {
        cout << "   4"
             << "\t" << eraser->productName << "\t \t" << eraser->price << "\t \t" << eraser->quantity;
    }
    cout << endl;
    if (calculator->quantity < 1)
    {
        cout << " Calculator Not Available" << endl;
    }
    else
    {
        cout << "   5"
             << "\t" << calculator->productName << "\t" << calculator->price << "\t \t" << calculator->quantity;
    }
    cout << endl;
}

void StartMenu()
{
    system("cls");
    cout << endl;
    cout << "  Main Menu  " << endl;
    cout << " ______________________________________ " << endl;
    cout << "  1.Admin Portal " << endl;
    cout << "  2.User Portal " << endl;
    cout << "  3.Exit " << endl;
    cout << " Please Select Your Option (1/2/3) : ";
    cin >> depart;
}

int main()
{

    int AddItem;
    string pass;
    int AdminSelection;
    int UserSelection;
    char choice = 'y'; 

    book = createNode(10, "Book", 40, book);
    map = createNode(10, "Map", 20, map);
    pencil = createNode(10, "Pencil", 30, pencil);
    eraser = createNode(10, "Eraser", 30, eraser);
    calculator = createNode(10, "Calculator", 60, calculator);
label1:
    StartMenu();
    system("cls");
    if (depart == 1)
    {
        cout << " Enter Admin Password : ";
        cin >> pass;
        if (pass == "admin")
        {
            system("cls");
            cout << endl;
            cout << "  Welcome Admin " << endl;
            cout << " ______________________________________ " << endl;
            cout << "  1. Increase Item's Quantity In the Machine  " << endl;
            cout << "  2. See Items In the Machine  " << endl;
            cout << "  3. Main Menu  " << endl;

            do
            {
                cout << " Select Operation To Be Performed (1/2/3): ";
                cin >> AdminSelection;
                if (AdminSelection == 1)
                {
                    cout << " Which Item's Quantity Do You Want To Increase? Enter Number" << endl;
                    cout << " 1.Book, 2.Map, 3.Pencil, 4.Eraser, 5.Calculator " << endl;
                    cin >> AddItem;
                    switch (AddItem)
                    {
                    case 1:
                        if (book->quantity < 5)
                        {
                            book = createNode(10, "Book", 30, book);
                            cout << " Item Added" << endl;
                        }
                        else
                        {
                            cout << " Sufficient Quantity Already Available" << endl;
                        }
                        break;
                    case 2:
                        if (map->quantity < 5)
                        {
                            map = createNode(10, "Map", 25, map);
                            cout << " Item Added" << endl;
                        }
                        else
                        {
                            cout << " Sufficient Quantity Already Available" << endl;
                        }
                        break;
                    case 3:
                        if (pencil->quantity < 5)
                        {
                            pencil = createNode(10, "Pencil", 50, pencil);
                            cout << " Item Added" << endl;
                        }
                        else
                        {
                            cout << " Sufficient Quantity Already Available" << endl;
                        }
                        break;
                    case 4:
                        if (eraser->quantity < 5)
                        {
                            eraser = createNode(10, "Eraser", 40, eraser);
                            cout << " Item Added" << endl;
                        }
                        else
                        {
                            cout << " Sufficient Quantity Already Available" << endl;
                        }
                        break;
                    case 5:
                        if (calculator->quantity < 5)
                        {
                            calculator = createNode(10, "Calculator", 60, calculator);
                            cout << " Item Added" << endl;
                        }
                        else
                        {
                            cout << " Sufficient Quantity Already Available" << endl;
                        }
                        break;
                    default:
                        cout << " Invalid Choice";
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            break;
                        }
                    }
                }
                else if (AdminSelection == 2)
                {
                    Traverse();
                }
                else if (AdminSelection == 3)
                {
                    goto label1;
                }
                else
                {
                    cout << " Wrong Input, Try Again" << endl;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
                cout << endl;
            } while (choice != 'N' && choice != 'n');
        }
        else
        {
            cout << " Wrong Password, Please try again" << endl;
            system("pause");
            goto label1;
        }
    }
    else if (depart == 2)
    {
        system("cls");
        cout << endl;
        Traverse();
        cout << "\n  Welcome User  " << endl;
        cout << " ______________________________________ " << endl;
        cout << "  1. Add To Cart" << endl;
        cout << "  2. View Cart And Purchase" << endl;
        cout << "  3. Main Menu" << endl;
        do
        {
            cout << " Select Operation To Be Performed (1/2/3) : ";
            cin >> UserSelection;
            if (UserSelection == 1)
            {
                cout << " Enter Item Number To Add In Cart: ";
                cin >> UserSelection;
                switch (UserSelection)
                {
                case 1:
                    book = Remove(book);
                    break;
                case 2:
                    map = Remove(map);
                    break;
                case 3:
                    pencil = Remove(pencil);
                    break;
                case 4:
                    eraser = Remove(eraser);
                    break;
                case 5:
                    calculator = Remove(calculator);
                    break;
                default:
                    cout << " Invalid Choice";
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        break;
                    }
                }
            }
            else if (UserSelection == 2)
            {

                if (total > 0)
                {
                    cout << " Item(s) In Cart: ";
                    for (int i = 0; i < items; i++)
                    {
                        cout << item[i] << "  ";
                    }
                    cout << endl;
                    cout << " Total Amount: ";
                    cout << total << endl;
                    cout << endl;
                    cout << " Proceeding To Purchase" << endl;
                    calculateChange(total);
                }
                else
                {
                    cout << " Cart Is Empty " << endl;
                }
            }
            else if (UserSelection == 3)
            {
                goto label1;
            }
            else
            {
                cout << " Wrong Input, Try Again " << endl;
                if (cin.fail())
                {
                    cin.ignore(10000, '\n');
                    cin.clear();
                }
            }
        } while (choice != 'N' && choice != 'n');
    }

    else if (depart == 3)
    {
        return 0;
    }
    else
    {
        if (cin.fail())
        {
            cin.clear();             
            cin.ignore(10000, '\n'); 
        }
        cout << " Wrong Input, Please Enter Either 1/2/3 \n";
        system("pause");
        goto label1;
    }
}
