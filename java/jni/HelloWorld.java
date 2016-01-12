class HelloWorld {
    private native void print();
    public static void main(String[] args) {
        new HelloWorld().print();
    }
    static {
//        System.out.println(System.getProperty("java.library.path"));
        System.loadLibrary("hello"); // This loads libhello.so
    }
}
