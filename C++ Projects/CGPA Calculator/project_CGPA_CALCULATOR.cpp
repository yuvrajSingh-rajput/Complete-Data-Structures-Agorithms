#include<iostream>
#include<fstream>
#include<limits>
#include<cstring>
#include<vector>
using namespace std;

class Course_structure{
    public:
    string course_name;
    char grade[2];
    int credits;

    public:
    Course_structure(){} // default Constructor;
    //* Constructor:
    Course_structure(const string& name,char g[],double c){
        course_name = name;
        strcpy(grade,g);
        credits = c;
    };
    double calculate_gradePoints() const{
        //! use cin.get(grade,3);

        if(grade[0]=='A' && grade[1]=='\0'){
            return 10.0;
        }else if(grade[0]=='A' && grade[1]=='B'){
            return 9.0;
        }else if(grade[0]=='B' && grade[1]=='\0'){
            return 8.0;
        }else if(grade[0]=='B' && grade[1]=='C'){
            return 7.0;
        }else if(grade[0]=='C' && grade[1]=='\0'){
            return 6.0;
        }else if(grade[0]=='C' && grade[1]=='D'){
            return 5.0;
        }else if(grade[0]=='D' && grade[1]=='\0'){
            return 4.0;
        }else if(grade[0]=='F' && grade[1]=='\0'){
            return 0.00;
        }else{
            return 0.00;
        }
    }
};

class CGPA_Calculator:virtual public Course_structure{
    public:
    static double total_Common_Grade_points;
    static double total_Credits;
    vector <Course_structure> courses;

    //!SGPI--> Total grade_points in individual semester;
    //! CGPI--> Total average grade_points of overall semester;

    public:
    void Add_Course_to_vector(const string& name,char grade[],double credits){
        Course_structure course(name,grade,credits);
        courses.push_back(course);
    }

    double Calculate_Semester_SGPI() const{
        double total_credits_per_sgpi = 0.00;
        double total_grade_points_per_sgpi = 0.00;

        for(const Course_structure& course: courses){
            total_credits_per_sgpi = total_credits_per_sgpi + course.credits;
            total_grade_points_per_sgpi = total_grade_points_per_sgpi + course.calculate_gradePoints() * course.credits;
        }
        return (double)(total_grade_points_per_sgpi)/(double)(total_credits_per_sgpi);
    }

    double Calculate_Total_CGPI() const{
        for(const Course_structure& course: courses){
            total_Credits = total_Credits + course.credits;
            total_Common_Grade_points = total_Common_Grade_points + course.calculate_gradePoints() * course.credits;
        }
        return (double)(total_Common_Grade_points)/(double)(total_Credits);
    }
};

double CGPA_Calculator::total_Common_Grade_points = 0.00;
double CGPA_Calculator::total_Credits = 0.00;

class Semester: virtual public Course_structure, public CGPA_Calculator{
    private:
    public:
};

int main(){
    int Total_number_of_ended_semester, total_courses;
    cout<<"Enter total number of semester passed till now: ";
    cin>>Total_number_of_ended_semester;
    Semester *semester = new Semester[Total_number_of_ended_semester];
    cout<<"Enter the number of total courses: ";
    cin>>total_courses;
    CGPA_Calculator calculator;
    for (int i = 0; i < Total_number_of_ended_semester; i++) {
        for (int j = 1; j <= total_courses; j++) {
            string name_of_course;
            char Grade_[3]; // Changed the size to 3 to accommodate two characters and a null terminator
            double per_credit;

            cout << "Enter the name of the course " << j << " in " << i + 1 << "th semester: ";
            cin.ignore(); // Clear newline character from previous input
            getline(cin, name_of_course);

            cout << "Enter the grade obtained of above subject in exam: ";
            cin.get(Grade_, 3);
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the remaining input buffer, including newline

            cout << "Enter the maximum credit of the above subject: ";
            cin >> per_credit;

            (semester + i)->Add_Course_to_vector(name_of_course, Grade_, per_credit);
        }
        (semester + i)->Calculate_Semester_SGPI();
        (semester + i)->Calculate_Total_CGPI();
    }

    ofstream text_file_of_result("test.txt");

    for (int i = 0; i < Total_number_of_ended_semester; i++) {
        text_file_of_result << " ----------------------------------" << endl;
        text_file_of_result << "|       RESULT FOR SEMESTER " << i + 1 << "     |" << endl;
        text_file_of_result << " ----------------------------------" << endl;
        text_file_of_result << endl << endl;
        text_file_of_result<<"COURSE NAME"<<"\t\t"<<"GRADE"<<"\t"<<"CREDITS"<<endl;
        
        // Write the grade results for this semester.
        for (const Course_structure& course : (semester + i)->courses) {
            text_file_of_result<<course.course_name<<"\t\t"<<course.grade<<"\t"<<course.credits<<endl;
        }
        text_file_of_result<<"S.G.P.I. = "<<(semester+i)->Calculate_Semester_SGPI()<<"\t C.G.P.I. = "<<(semester+i)->Calculate_Total_CGPI()<<endl<<endl;
    }

    text_file_of_result.close();
    delete[] semester;
    return 0;
}