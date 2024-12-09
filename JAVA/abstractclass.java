abstract class Shape {
    int a;
    int b;

    abstract void printArea();
}

class Rectangle extends Shape {
    Rectangle(int l, int b) {
        this.a = l;
        this.b = b;
    }

    void printArea() {
        double area = a * b;
        System.out.println("Area of rectangle is: " + area);
    }
}

class Triangle extends Shape {
    Triangle(int ba, int h) {
        this.a = ba;
        this.b = h;
    }

    void printArea() {
        double area = 0.5 * a * b;
        System.out.println("Area of Triangle = " + area);
    }
}

class Circle extends Shape {
    int r;

    Circle(int r) {
        this.r = r;
    }

    void printArea() {
        double area = 3.14 * r * r;
        System.out.println("Area of Circle = " + area);
    }
}

public class abstractclass {
    public static void main(String[] args) {
        Rectangle rectangle = new Rectangle(10, 5);
        Triangle triangle = new Triangle(10, 8);
        Circle circle = new Circle(7);

        rectangle.printArea();
        triangle.printArea();
        circle.printArea();
    }
}
