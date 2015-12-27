#include "System.h"
#include "User.h"

System::System()
{
    //ctor
}

System::~System()
{
    //dtor
}
bool System::validName(string s)
{
    bool n = s.size() > 0 ;

    for (int i = 0 ; i < s.size()  ; i++)
    {
        if ( (s[i] >= 65 && s[i] <= 90 ) || (s[i] >= 97 && s[i] <= 122) || s[i] == ' ')
            continue ;
        else
            return 0 ;
    }
    return 1 && s.size() ;
}

bool System::strongPassword(string P)
{
    int sz = int (P.size()) ;
    bool U , L , D ;
    for (int i = 0 ; i < sz ; i++)
    {
        if (islower(P[i]))
            L = true ;
        else if (isupper(P[i]))
            U = true ;
        else if (isdigit(P[i]))
            D = true ;
    }
    return sz >= 8 && L && U && D ;
}
bool System::validEmail(string P)
{
    int f1 = P.rfind('@') ;
    int f2 = P.rfind(".com") ;
    int f3 = P.find(' ') ;
    return  f1 != -1 && f2 != -1 && (f2 - f1) > 1  && f3 == -1;
}
bool  System:: validAccount()
{
    return numOfUsers < 100 ;
}
void System:: AddUser(User U)
{
    User *temp = new User[numOfUsers + 1] ;
    for (int i = 0 ; i < numOfUsers ; i++ )
    {
        temp[i] = listOfUsers[i] ;
    }
    temp[numOfUsers] = U ;
    listOfUsers = new User[++numOfUsers] ;
    for (int i = 0 ; i <numOfUsers ; i++ )
        listOfUsers[i] = temp[i] ;
    delete []temp ;
}
void System::merge_sort(User *a, int n)
{
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}
bool System::validInfo(User U) // not completed !
{
    bool e = validEmail(U.getEmail()) ;
}
void System::Sort()
{
    merge_sort(listOfUsers, numOfUsers );
}
void System::merge(User *a, int n, int m)
{
    int i = 0, j = m;
    User *b = new User[n];
    for (int k = 0; k < n; ++k)
    {
        if (i == m)
            b[k] = a[j++];
        else if (j == n)
            b[k] = a[i++];
        else if (a[i].getName() <= a[j].getName())
            b[k] = a[i++];
        else
        {
            b[k] = a[j++];
        }
    }
    for (int k = 0; k < n; ++k)
        a[k] = b[k];
    delete[] b;
}
int System::findUser(int lower, int upper, string email)
{
    if (lower > upper)
        return -1;
    int mid = (lower + upper) / 2;
    if (listOfUsers[mid].getEmail() > email)
        return findUser(lower, mid - 1, email);
    else if (listOfUsers[mid].getEmail() < email)
        return findUser(mid + 1, upper, email);
    else return mid;
}
/// test sorting of user :
//
void System::show()
{
    for (int i = 0 ; i <numOfUsers ; i++)
        cout << listOfUsers[i].getName() <<endl;
}
void System::removeAccount(User user)
{
    int index = findUser(0, numOfUsers - 1, user.getEmail());

    numOfUsers--;

    for (int i = index; i < numOfUsers; i++)
        listOfUsers[i] = listOfUsers[i + 1];
}
void System::signUp()
{
    if (!validAccount())
    {
        cout << "Sorry ,You cannot sign up\n";
        return ;
    }
    User u ;
    string s = "0" ;
    while(!validName(s))
    {
        cout << "Name : " ;
        getline(cin , s) ;
    }
    u.setName(s);
    s = "0";
    while(!validEmail(s))
    {
        cout << "Email: " ;
        getline(cin , s) ;
    }
    u.setEmail(s);
    s = "0";
    while(!strongPassword(s))
    {
        cout << "Password: " ;
        getline(cin , s) ;
    }
    u.setPassword(s);
    int choice = -1 ;
    while(choice == -1)
    {
        cout << "Gender (1 for male , 2 for female) :" ;
        cin >> choice ;

        if (choice == 1)
            u.setGender("male") ;
        else if (choice == 2)
            u.setGender("female") ;
        else
            choice = -1;
    }
    while(8)
    {
        cout << "Enter your date of birth in the format 00/00/0000 : " ;
        cin >> s ; /// not completed .
        break ;
    }
    AddUser(u);
}
User System::search(string)
{
}
void System::signIn()
{
    string e , p ;

        cout << "Email :" ;
        cin >> e ;
        int idx  = findUser(0 , numOfUsers , e) ;
        while (idx == -1)
        {
            cout << "Email does not exist please Enter it again :\nEmail:" ;
            cin >> e ;
            idx  = findUser(0 , numOfUsers , e) ;
        }
        cout << "Password :";
        cin >> p;
        while(listOfUsers[idx].getPassword() != p )
        {
            cout << "Invalid password .. please Enter again : ";
            cin >> p ;
        }


}
