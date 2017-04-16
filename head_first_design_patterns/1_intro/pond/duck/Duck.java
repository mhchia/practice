package pond.duck;
public abstract class Duck {
    public FlyBehavior flyBehavior;
    public QuackBehavior quackBehavior;

    public Duck() {
    }

    // display must be different among ducks, so it should be implemented by subclasses.
    public abstract void display();

    public void performFly() {
        flyBehavior.fly();
    }

    public void performQuack() {
        // the Duck object delegates that behavior to the object referenced by quackBehavior
        quackBehavior.quack();
    }

    public void swim() {
        System.out.println("All ducks float");
    }

    public void changeFlying(FlyBehavior flyBehavior) {
        this.flyBehavior = flyBehavior;
    }
}

