import CIE.*;
import SEE.*;

public class FinalMarks {
    public static void main(String[] args) {
        // Initialize data for 2 students
        External[] students = {
            new External("1BM20CS001", "Alice", 5, new int[]{80, 85, 90, 75, 88}),
            new External("1BM20CS002", "Bob", 5, new int[]{70, 80, 85, 60, 75})
        };

        Internals[] internalMarks = {
            new Internals(new int[]{20, 22, 24, 19, 23}),
            new Internals(new int[]{18, 20, 22, 17, 21})
        };

        // Display Final Marks
        System.out.println("Final Marks of Students:");
        for (int i = 0; i < students.length; i++) {
            System.out.println("Student " + (i + 1) + " (" + students[i].name + ", USN: " + students[i].usn + "):");
            for (int j = 0; j < 5; j++) {
                int finalMarks = internalMarks[i].internalMarks[j] + (students[i].externalMarks[j] / 2);
                System.out.println("Course " + (j + 1) + ": " + finalMarks);
            }
            System.out.println();
        }
    }
}
