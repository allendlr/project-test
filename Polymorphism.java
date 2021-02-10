class Person{
    protected String name;
    protected int age;
    protected String gender;
    
    Person(String name,int age,String gender){
        this.name = name;
        this.age = age;
        this.gender = gender;
    }

    public String getName(){
        return this.name;
    }

    public int getAge(){
        return this.age;
    }

    public String getGender(){
        return this.gender;
    }
}

class Student extends Person{
    private int grade;

    Student(String name,int age,String gender, int grade){
        super(name,age,gender);
        this.grade =grade;
    }

    public int getGrade(){
        return this.grade;
    }

}

class Teacher extends Person{
    private double salary;
    Teacher(String name,int age,String gender, double salary){
        super(name,age,gender);
        this.salary = salary;
    }
    public double getSalary(){
        return this.salary;
    }
}

public class Polymorphism {
    public static void main(String[] args){
        Student s1 = new Student("Mark",12,"M",85);
        Student s2 = new Student("Jane",13,"F",86);
        Teacher t = new Teacher("Gates",47,"M", 70231.97);

        //s1
        System.out.println("Student 1:");
        System.out.println("Name: " + s1.getName());
        System.out.println("Age: " + s1.getAge());
        System.out.println("Gender: " + s1.getGender());
        System.out.println("Grade: " + s1.getGrade());
        //s2
        System.out.println("\nStudent 2:");
        System.out.println("Name: " + s2.getName());
        System.out.println("Age: " + s2.getAge());
        System.out.println("Gender: " + s2.getGender());
        System.out.println("Grade: " + s2.getGrade());
        //teacher (t)
        System.out.println("\nTeacher:");
        System.out.println("Name: " + t.getName());
        System.out.println("Age: " + t.getAge());
        System.out.println("Gender: " + t.getGender());
        System.out.println("Grade: " + t.getSalary());
    }
}
