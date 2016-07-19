class Student {
    private String rollNo;
    private String name;

    public String getRollNo() {
        return rollNo;
    }

    public void setRollNo(String rollNo) {
        this.rollNo = rollNo;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}

class StudentView {
    public void printStudentDetails(String studentName, String studentRollNo) {
        System.out.println("Student: ");
        System.out.println("Name:    " + studentName);
        System.out.println("Roll No: " + studentRollNo);
    }
}

class StudentController {

    private Student model;
    private StudentView view;

    public StudentController(Student model, StudentView view) {
        this.model = model;
        this.view = view;
    }

    /*
    public void setStudentName(String name) {
        model.setName(name);
    }

    public void setStudentRollNo(String rollNo) {
        model.setRollNo(rollNo);
    }

    public String getStudentName() {
        return model.getName();
    }

    public String getStudentRollNo() {
        return model.getRollNo();
    }
    */
    public void setStudent(Student student) {
        model = student;
    }
    public Student getStudent() {
        return model;
    }

    public void updateView() {
        view.printStudentDetails(model.getName(), model.getRollNo());
    }

}

public class MVCPatternDemo {

    private static int studentCount = 0;

    public static void main(String[] args) {

        // init the view : to write student details on console
        StudentView view = new StudentView();

        // get a model from database
        Student model = getStudentFromDatabase();

        // init the controller
        StudentController controller = new StudentController(model, view);

        // controller use model to update the view
        controller.updateView();

        // get a new model
        model = getStudentFromDatabase();

        // pass the model to controller
        controller.setStudent(model);

        // controller use model to update the view
        controller.updateView();

    }

    public static Student getStudentFromDatabase() {
        Student student = new Student();
        student.setName("Student" + studentCount);
        student.setRollNo(Integer.toString(studentCount));
        studentCount += 1;
        return student;
    }

}
