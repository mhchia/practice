package pond.duck;

abstract class Animal {
    abstract void makeSound();
};

class Dog extends Animal {
    void makeSound()
    {
        bark();
    }
    void bark()
    {
        System.out.println("bark");
    }
};

public class Test {
    public static void main(String[] args) {
//        Dog dog = new Dog();
        /*
        // programming to interface/supertype
        Animal dog = new Dog();
        */
        // we don't know WHAT the actual animal type is, ALL we care about is that it knows how to respond to makeSound()
        Animal a = getAnimal();
        a.makeSound();
    }
    private static Animal getAnimal()
    {
        return new Dog();
    }
};
