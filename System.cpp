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

////////////////////////////

bool System::validName(string s)
{
    for (int i = 0 ; i < s.size()  ; i++)
    {
        if ( (s[i] >= 65 && s[i] <= 90 ) || (s[i] >= 97 && s[i] <= 122) || s[i] == ' ')
            continue ;
        else
            return 0 ;
    }
    return s.size() ;
}

////////////////////////////////////

bool System::strongPassword(string P)
{
    int sz = int (P.size()) ;
    bool U  = false , L = false  , D = false  ;
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

///////////////////////////////////////

int System::validEmail(string P)
{
    int f1 = P.rfind('@') ;
    int f2 = P.rfind(".com") ;
    int f3 = P.find(' ') ;

    int x = findUser(0,numOfUsers,P);
    bool b = f1 != -1 && f2 != -1 && (f2 - f1) > 1  && f3 == -1 ;
    if (x == -1 && b) return 1;
    if (x != -1) return 2;
    return 3  ;
}

//////////////////////////

bool  System:: validAccount()
{
    return numOfUsers < 100 ;
}

///////////////////


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
    merge_sort(listOfUsers, numOfUsers );
}

///////////////////

void System::merge_sort(User *a, int n)
{
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}

/////////////////////////////

bool System::validInfo(User U) // not completed !
{
    bool e = validEmail(U.getEmail()) ;
}

/////////////////


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

/////////////////

int System::findUser(int lower , int upper , string email)
{
    if (numOfUsers == 0)
        return -1;
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
/////////////////////



void System::show()
{
    for (int i = 0 ; i <numOfUsers ; i++)
        cout << listOfUsers[i].getName() <<endl;
}

/////////////////


void System::removeAccount(User user )
{
    int index = findUser(0, numOfUsers - 1, user.getEmail());

    numOfUsers--;

    for (int i = index; i < numOfUsers; i++)
        listOfUsers[i] = listOfUsers[i + 1];
    user.remove(user) ;

}

///////////////


void System::signUp()
{
    if (!validAccount())
    {
        cout << "Sorry ,You cannot sign up\n";
        return ;
    }
    cout << "\t\t\t Welcome ..\nSign Up :\n\n";
    User u ;
    string s;
    while(1)
    {
        cout << "Fill these Information\n" << endl;
        try
        {

            int choice ;
            cout << "Name : ";

            s = "";
            while(s == "")
                getline(cin , s);
            u.setName(s) ;
            cout << "Password : ";
            cin >> s;
            u.setPassword(s) ;
            cout << "Gender (1 for Male , 2 for Female ) : ";
            cin >> choice;

            u.setGender(choice) ;
            cout << "Email : " ;
            cin >> s ;
            u.setEmail(s);
            string month , day , year ;
            cout << "Enter day month year\n";
            cin >> day >> month >> year ;
            if (day.size() == 1)
                day = '0' + day ;
            if (month.size() == 1)
                month = '0' + month ;
            string s = day + '/' + month + '/' + year ;cout << s <<endl;
            u.setBirthDate(s);

            cout << endl;
            break;

        }
        catch(const char *s)
        {
            cout << s << endl;
            continue ;
        }
    }

    AddUser(u);
}

/////////////////////////

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
    loggedInUser = listOfUsers[idx] ;
    cout << loggedInUser.getName()  << endl;
}

/////////////////////////

User System::searchUser(string e)
{
    for (int i = 0 ; i < numOfUsers ; i++ )
    {
        if (listOfUsers[i].getEmail() == e)
            return listOfUsers[i];
    }
    User U;
    U.setName("NoUser") ;
    return U ;
}

///////////////////////////////////

bool System::validDate(string s)
{
    int sz = s.size() ;
    int day = (int(s[0] - '0') * 10 + int(s[1] - '0')) ;
    int month = (int(s[3] - '0') * 10 + int(s[4] - '0')) ;
    int year = (int(s[6] - '0') * 1000 + int(s[7] - '0') * 100 + int(s[8] - '0') * 10 + int(s[9] - '0')) ;
    return  isdigit(s[0]) && isdigit(s[1]) && isdigit(s[3]) && isdigit(s[4])
           && isdigit(s[6]) && isdigit(s[7]) && isdigit(s[8]) && isdigit(s[9]) && s[2] == '/' && s[5] == '/'
           &&  day <= 31 && day >= 1 &&  month <= 12 && month >= 1 && year >= 1900 && year <= 2014  ;
}
void tolow
