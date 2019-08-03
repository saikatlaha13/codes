#include"header.h"

int options_display()
{
    int option;   
    cout<<"\n Enter your choice";
	cout<<"\n 1. Register";
	cout<<"\n 2. login";
	cout<<"\n 3. Display details";
	cout<<"\n 4. Modify details";
	cout<<"\n 5. Exit \n";

    cin>>option;

    return option;
}

void user_choice()
{
    int choice=0;
    Employee operation;
    system("clear");
    cout<<"--------------Employee Project-----------\n"<<flush;

    choice=options_display();

    switch(choice)
    {
        case CHOICE_1:
            // register new employee
            operation.register_new_user(&operation);
            break;

        case CHOICE_2:
            // for logging in existing employee
            operation.login_existing_user(&operation);
            break;

        case CHOICE_3:
            // Fetch the record
            operation.display_employee_details(&operation);
            break;

        case CHOICE_4:	
            // Edit the record
            operation.modify_employee_details(&operation);
            break;

        case CHOICE_5:
            // Exit the program
            exit(0);
            break;

        default:
            // if the user enter wrong choice    
            cout<<"\n Please enter a correct input \n";
            //user_choice();
    }
    //user_choice();

    return ;
}

void Employee::display_employee_details(Employee* disp_ptr){
    
    int ch;
    File_opr file_op_obj;
    Node* head;
    linked_list object_list;
    Emp_cred_ver ver_obj;
    int result_of_data_found;
    Employee login_obj;
    
    cout<<"welcome to display\n"<<flush;
    head=file_op_obj.read_complete_data("database.txt",MODE_READ);
    object_list.display_data_linked_list(&head);
    
    cout<<"pless enter to continue..."<<endl;
   
    cin.ignore();
    cin.get();
    user_choice();
    return;
}

void Employee::modify_employee_details(Employee* modify_ptr){
    
    //system("clear");
    Node* head;
    File_opr file_op_obj;
    Emp_cred_ver ver_obj;
    int result_of_data_found;
    char new_data[50];
    Employee modify_ptr_new;
    
    cout<<"welcome to modify\n"<<flush;
    
    read_data_from_user(modify_ptr);
    
    head=file_op_obj.read_complete_data("database.txt",MODE_READ);
    
    result_of_data_found=ver_obj.parse_data_link_list(modify_ptr,head);
    
    if(result_of_data_found == MATCH_FOUND)
    {
       cout<<"result found in line no:"<<file_line_count<<endl;
       cout<<"enter new details"<<endl;
       read_data_from_user(&modify_ptr_new);
       edit_database(modify_ptr,&modify_ptr_new,&(new_data[0]));
    }
    else
    {
        cout<<"data not present"<<endl;
    }
    //user_choice();
    return;
}

void Employee::login_existing_user(Employee* login_ptr){

    //system("clear");
    File_opr file_op_obj;
    Node* head;
    Emp_cred_ver ver_obj;
    int result_of_data_found;
    Employee login_obj;

    cout<<"-------welcome to login page-------"<<"\n"<<flush;

    login_obj.input_login_details(login_ptr);
    
    head=file_op_obj.read_complete_data("database.txt",MODE_READ);
    
    result_of_data_found=ver_obj.parse_data_link_list(login_ptr,head);
    
    if(result_of_data_found == MATCH_FOUND)
    {
       cout<<"you are logged in"<<endl;
    }
    
    if(result_of_data_found == MATCH_NOT_FOUND)
    {
       cout<<"credentials are not present you cannot log in"<<endl;
       cout<<"please register yourself first"<<endl;
    }
    
    cout<<"pless enter to continue..."<<endl;
    cin.ignore();
    cin.get();
    user_choice();
}
    

void Employee::register_new_user(Employee* regt_ptr){

    // object for performing file operations
    File_opr file_op_obj;
    Node* head;
    Emp_cred_ver ver_obj;
    int result_of_data_found;

    // filename
    file_op_obj.filename="database.txt";

    // for reading credentials
    read_data_from_user(regt_ptr);

    //fetching the head after reading all the data from database
    head=file_op_obj.read_complete_data(file_op_obj.filename,MODE_READ);
    
    result_of_data_found=ver_obj.parse_data_link_list(regt_ptr,head);

    if(result_of_data_found == MATCH_FOUND)
    {
       cout<<"credentials already exists please enter new credentials"<<endl;
       file_op_obj.register_new_user(regt_ptr);
    }
    
    if(result_of_data_found == MATCH_NOT_FOUND)
    {
       cout<<"data does not exists added to database"<<endl;
       file_op_obj.write_to_file(regt_ptr,file_op_obj.filename,MODE_APPEND); 
    }
    cout<<"pless enter to continue..."<<endl;
    cin.ignore();
    cin.get();
    user_choice();

    return;
}

// generic read user data function
void read_data_from_user(Employee* user_input){

    cout<<"-------enter the credentials-------"<<"\n";

    cout<<"\n"<<"enter your username:"<<endl;
    cin>>(*user_input).username;

    cout<<"\n"<<"enter your password:"<<endl;
    cin>>(*user_input).password;

    cout<<"\n"<<"enter your email id:"<<endl;
    cin>>(*user_input).email;

    cout<<"\n"<<"enter your department:"<<endl;
    cin>>(*user_input).department;
 
    return;
}

void Employee::input_login_details(Employee* login_input)
{
    cout<<"-------enter the credentials to login-------"<<"\n";

    cout<<"\n"<<"enter your username:"<<endl;
    cin>>(*login_input).username;

    cout<<"\n"<<"enter your password:"<<endl;
    cin>>(*login_input).password;

    cout<<"\n"<<"enter your email id:"<<endl;
    cin>>(*login_input).email;
}

