  
  #include <iostream>
 
  #include <fstream>

  using namespace std;

 class temp {   // creation
	
    string userName, email, password;
    
	string searchName, searchPass, searchEmail;
   
    fstream file;
    
 public:
    
	void login();
    void signUp();
    void forget();
 };
 temp obj;

 int main () {
    char choice;
   
    while (true) {
       
	    cout << "1- login : " << endl;
        
		cout << "2- sign up : " << endl;
        
		cout << "3- forget password: " << endl;
       
	    cout << "4- exit : " << endl;
        
		cout << "Enter your choice: ";
        
		cin >> choice;
       
	    cin.ignore();  

        switch (choice) {
            case '1':
                obj.login();
               
			    break;
            case '2':
                obj.signUp();
                
				break;
            case '3':
                obj.forget();
               
			    break;
            case '4':
                
				return 0;
		    default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

  void temp :: signUp() {
   
   
    cout << "Enter user name: ";
    
	cin.ignore();
    
	getline(cin, userName);
  
    cout << "Enter user email address: ";
 
    getline(cin, email);
   
    cout << "Enter user password: ";
   
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
  
    if (file.is_open()) {
   
        file << userName << "*" << email << "*" << password << "\n";
   
        file.close();
  
        cout << "Signup successful!" << endl;
  
    } else {
    
	    cout << "Unable to open file for writing." << endl;
    
	}
}

void temp::login() {                                 //   function defination

    cout << ".......login....... " << endl;           // we will call from class in this part
    
	cout << "Enter user name: ";
   
    cin.ignore();
    
	getline(cin, searchName);
    
	cout << "Enter user password: ";
   
    getline(cin, searchPass);

    
	file.open("loginData.txt", ios::in);
    
	if (file.is_open()) {
        
		bool found = false;
        
		while (!file.eof()) {
           
		    getline(file, userName, '*');
            
			getline(file, email, '*');
            
			getline(file, password, '\n');
            
		if (userName == searchName) {
    
	        if (password == searchPass) {
        
		    cout << "Account login successful!" << endl;
    
			cout << "Username: " << userName << endl;

			cout << "Email: " << email << endl;
                
			found = true;
                 
			break;
              
	   } else {
                   
	       cout << "Password is incorrect!" << endl;
                   
		    found = true;
                   
		    break;
       }
     }
  }
        if (!found) {
    
		    cout << "Username not found." << endl;
        
		}
       
	    file.close();
    
	} else {
       
	    cout << "Unable to open file for reading." << endl;
    
	}
}

 void temp::forget() {
    
	cout << "Enter user name: ";
   
    cin.ignore();
   
    getline(cin, searchName);
   
    cout << "Enter user email: ";
   
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
   
    if (file.is_open()) {
   
        bool found = false;
   
        while (!file.eof()) {
  
            getline(file, userName, '*');
      
	        getline(file, email, '*');
         
		    getline(file, password, '\n');
      
	        if (userName == searchName && email == searchEmail) {
            
			    cout << "Account found!" << endl;
             
			    cout << "Your password: " << password << endl;
              
			    found = true;
               
			    break;
            }
        }
      
	    if (!found) {
       
	        cout << "No matching account found." << endl;
  
        }
   
        file.close();
  
    } else {
  
        cout << "Unable to open file for reading." << endl;
  
    }
}






