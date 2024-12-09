// Write a Java  program that demonstrates handling of exceptions in inheritance tree. Create a base class called “Father” and derived class called “Son” which extends the base class. In Father class, implement a constructor which takes the age and throws the exception WrongAge( ) when
// the input age<0. 
// In Son class, implement a constructor that uses both father and son’s age and throws an
// exception if son’s age is >=father’s age.

class WrongAgeException extends Exception {
    WrongAgeException(String message){
        super(message);
    }
}

class Father {
    int age;
    Father(int age) throws WrongAgeException {
        if(age<0){
            throw new WrongAgeException("Age cannot be negative");
        }
        this.age = age;
    
}
}

class Son extends Father{
    int sonAge;
    Son(int fatherAge, int sonAge) throws WrongAgeException {
        super(fatherAge);
        if(sonAge>=fatherAge){
            throw new WrongAgeException( "Son age cannot be more than fathers age");
        }
        this.sonAge = sonAge;
    }
}
public class father{
    public static void main(String[] args) {
        try{
            Father f1 = new Father(-2);

        }catch(Exception e){
            System.out.println(e.getMessage());
        }
        try{
            Son s1 = new Son(34,36);

        }catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}

/*
Output:
Age cannot be negative
Son age cannot be more than fathers age
 */