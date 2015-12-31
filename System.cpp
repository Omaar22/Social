#include "System.h"
#include "User.h"

System::System() : numOfUsers(0) , listOfUsers( new User[100] ) {}
System::~System() {}


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
bool System::validEmail(string P)
{
    int f1 = P.rfind('@') ;
    int f2 = P.rfind(".com") ;
    int f3 = P.find(' ') ;
    return  f1 != -1 && f2 != -1 && (f2 - f1) > 1  && f3 == -1;
}
bool System::validAccount()
{
    return numOfUsers < 100 ;
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

///////////////////////

void System:: AddUser(User U)
{
    listOfUsers[ numOfUsers++ ] = U ;
    merge_sort(listOfUsers, numOfUsers );

}
int System::findUser(string email)
{
    for(int i=0 ; i< numOfUsers ; i++)
    {
        if( listOfUsers[i].getEmail() == email)
            return i;
    }
    return -1 ;
}
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

///////////////////

void System::merge_sort(User *a, int n)
{
    if (n < 2) return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}
void System::merge(User *a, int n, int m)
{
    int i = 0, j = m;
    User *b = new User[n];

    for (int k = 0; k < n; ++k)
    {
        if (i == m) b[k] = a[j++];
        else if (j == n) b[k] = a[i++];
        else if (a[i].getName() <= a[j].getName()) b[k] = a[i++];
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

void System::signIn()
{
    string e , p ;

    cout << "\t\t Sign In:\n\nEmail: " ;
    cin >> e ;
    int idx  = findUser(e) ;
    while (idx == -1)
    {
        cout << "Email does not exist please Enter it again :\nEmail: " ;
        cin >> e ;
        idx  = findUser(e) ;
    }
    cout << "Password :";
    cin >> p;
    while(listOfUsers[idx].getPassword() != p )
    {
        cout << "Invalid password .. please Enter again: ";
        cin >> p ;
    }
    loggedInUser = listOfUsers[idx] ;
}
void System::removeAccount(User user )
{
    int index = findUser(user.getEmail());

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

    cout << "\t\t\t Welcome ..\nSign Up :\n\n";
    User u ;

    string s;
    while(8)
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

            cout << "Email : " ;
            cin >> s ;
            u.setEmail(s);

            cout << "Password : ";
            cin >> s;
            u.setPassword(s) ;

            cout << "Gender (1 for Male , 2 for Female ) : ";
            cin >> choice;
            u.setGender(choice) ;

            string month , day , year ;
            cout << "Day: ";
            cin >> day ;
            cout << "Month: ";
            cin >> month ;
            cout << "Year: ";
            cin >> year ;

            if (day.size() == 1) day = '0' + day ;
            if (month.size() == 1) month = '0' + month ;
            string s = day + '/' + month + '/' + year ;
            u.setBirthDate(s);

            cout << endl;
            break;

        }
        catch(const char *c)
        {
            cout << c << endl;
            continue ;
        }
    }

    AddUser(u);
    loggedInUser = u ;
    merge_sort(listOfUsers , numOfUsers) ;

}
void System::startMinue()
{
here:
    cout << "\t\t\t\t\t\t WELCOME ... \n\n";
    cout << "\n\n\t\t1. Sign Up\n\t\t2. Sign In\n\t\t3. Exit\n\n";
    int x ;
    cout << "Your choice: ";
    cin >> x ;
    while(x < 0 || x > 3)
    {
        cout << "Wrong choice , Enter Again :";
        cin >> x;
    }
    if( x == 1 ) signUp();
    if( x == 2 ) signIn();
    else if (x == 3) return ;

   // if (system("CLS")) system("clear");

    while(8)
    {
       // if (system("CLS")) system("clear");
        int choice ;
        string s ;
        cout << "1. View Profile\n2. Search Friend\n3. Add Post\n4. View Posts\n5. View Friends\n6. Message\n7. Sign Out\n";
        cout << "Enter Your Choice: ";
        cin >> choice ;
        while( choice < 1 && choice > 5 )
        {
            cout << "Wrong choice, Enter Again: ";
            cin >> choice ;
        }
        if( choice == 1 )
        {
            //if (system("CLS")) system("clear");
            cout << "\t\t Welcome, " << loggedInUser.getName() << "\n\n";
            loggedInUser.viewInfo( loggedInUser.getEmail() ) ;
            merge_sort(listOfUsers , numOfUsers ) ;
        }
        else if( choice == 2 )
        {
        //    if (system("CLS")) system("clear");
            cout << "Enter Email: ";
            cin >> s ;
            User u ;
            u = searchUser(s);
            if( u.getName() == "NoUser") cout << "No such user exist!";
            else u.viewUser( &loggedInUser );
        }
        else if (choice == 3)
        {
          //  if (system("CLS")) system("clear");
            loggedInUser.addPost();
        }
        else if (choice == 4 )
        {
          //  if (system("CLS")) system("clear");
            loggedInUser.viewPosts();
        }
        else if (choice == 5 )
        {
         //   if (system("CLS")) system("clear");
            loggedInUser.viewFriends();
        }
        else if (choice == 6 )
        {
      //      if (system("CLS")) system("clear");
            int x ;
            cout << "1. Send Message\n2. View Sent Messages\n3. View Received Messages\n4. Back\n";
            cin >> x ;

            while( x < 0 || x > 4 )
            {
                cout << "Wrong Choice, Enter Again: ";
                cin >> x ;
            }
            if( x == 1 )
            {
                string mail ;
                cout << "Email :";
                cin >> mail ;

                User U ;
                U = searchUser( mail ) ;
                if( U.getName() == "NoUser" ) cout << "No Such User Exist! ";
                else loggedInUser.sendMessageFun(&U);
            }
            if (x == 2)
            {
                loggedInUser.viewSentMessages() ;
            }
            else if( x == 3 )
            {
                loggedInUser.viewReceivedMessages() ;
            }

        }
        else if (choice == 7 )
        {
            goto here ;
        }
    }
}
