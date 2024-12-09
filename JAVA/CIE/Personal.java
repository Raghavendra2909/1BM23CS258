package CIE;

public class Personal {
    public String usn;   // Public to allow access in the main file
    public String name;  // Public to allow access in the main file
    public int sem;      // Public to allow access in the main file

    public Personal(String usn, String name, int sem) {
        this.usn = usn;
        this.name = name;
        this.sem = sem;
    }
}
