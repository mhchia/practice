interface PointCornerFactory {
    Point getPoint();
    Corner getCorner();
}

interface Point {
    void line(int width);
}

interface Corner {
    void leftUp();
    void rightUp();
    void leftDown();
    void rightDown();
}

class Rectangle {
    private int width;
    private int height;
    
    Rectangle(int width, int height) {
        this.width = width;
        this.height = height;
    }
    
    void paint(PointCornerFactory factory) {
        Point point = factory.getPoint();
        Corner corner = factory.getCorner();
        corner.leftUp();
        point.line(width - 2);
        corner.rightUp();
        System.out.println();
        for(int i = 0; i < height - 2; i++) {
            point.line(width);
            System.out.println();
        }
        corner.leftDown();
        point.line(width - 2);
        corner.rightDown();
        System.out.println();
    }
}
public class Main {
    public static void main(String[] args) {
        Rectangle rect = new Rectangle(20, 10);
        PointCornerFactory factory =
            new PointCornerFactory() {
                public Point getPoint() {
                    return new Point() {
                        public void line(int width) {
                            for(int i = 0; i < width; i++) {
                                System.out.print("-");
                            }
                        }
                    };
                }
                
                public Corner getCorner() {
                    return new Corner() {
                        public void leftUp() { System.out.print('+'); }
                        public void rightUp() { System.out.print('+'); }
                        public void leftDown() { System.out.print('+'); }
                        public void rightDown() { System.out.print('+'); }
                    };
                }
            };
        rect.paint(factory);        
    }
}
