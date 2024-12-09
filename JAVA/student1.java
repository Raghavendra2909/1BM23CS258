/*Create two classes- Student and Internals. 

    The class student has members like usn, name, sem.

    The class internals has an array that stores the internal marks scored in five courses of the current  semester of the student. 


Create another class External which is a derived class of Student. This class has an array that stores the SEE marks scored in five courses of the current semester of the student. 

 */
class Student {
    String usn;
    String name;
    int sem;
    Student(String usn, String name, int sem){
        this.usn = usn;
        this.name = name;
        this.sem = sem;
    }
    void display(){
        System.out.println("USN = "+usn);
        System.out.println("Name = "+name);
        System.out.println("Sem = "+sem);
    }
}

class Internals extends Student {
    int[] internalMarks;
    Internals(String usn, String name, int sem, int[] internalMarks){
        super(usn,name,sem);
        this.internalMarks = internalMarks;
    }
    void display(){
        for(int i = 0; i < internalMarks.length; i++){
            System.out.println(internalMarks[i]);
        }
    }
}
//external
class External extends Student{
    int[] see;
    Internals  internals;
    
    External(String usn, String name, int sem, int[] see, int[] internalMarks){
        super(usn, name, sem);
        this.see = see;
        this.internals = new Internals(usn, name, sem, internalMarks);
    }
    void display(){
        super.display();
        System.out.println("SEE marks:");
        for(int i = 0; i < see.length; i++){
            System.out.println(see[i]);
        }
        System.out.println("Internal marks");
        internals.display();
    }
}
public class student1 {
    public static void main(String[] args) {
        int[] see = {90, 80, 70,45,90};
        int[] internalMarks = {85, 75, 65,65,78};
        External e = new External("1BM23CS6647", "Rahul", 3,  see, internalMarks);
        e.display();
        }
    }
