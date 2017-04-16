abstract class Duck {
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

    public void setFlyBehavior(FlyBehavior flyBehavior) {
        this.flyBehavior = flyBehavior;
    }

    public void setQuackBehavior(QuackBehavior quackBehavior) {
        this.quackBehavior = quackBehavior;
    }
}


interface FlyBehavior
{
    public void fly();

}
class FlyNoWay implements FlyBehavior
{
    public void fly()
    {
        // do nothing, cannot fly
        System.out.println("I can't fly");
    }
}

class FlyWithWings implements FlyBehavior
{
    public void fly()
    {
        // fly using wings
        System.out.println("I'm flying!!");
    }
}

class MuteQuack implements QuackBehavior
{
    public void quack()
    {
        // do nothing, cannot quack
        System.out.println("<< Silence >>");
    }
}
class Quack implements QuackBehavior
{
    public void quack()
    {
        // quack
        System.out.println("Quack");
    }
}
interface QuackBehavior
{
    public void quack();
}
class Squeak implements QuackBehavior
{
    public void quack()
    {
        // squeak
        System.out.println("Squeak");
    }
}

class MallardDuck extends Duck {

    public MallardDuck() {
        // A mallardDuck uses the Quack class to handle its quack, so when performQuack is called,
        // the responsibility for the quack is delegated to the Quack object and we get a real quack.
        quackBehavior = new Quack();
        // it uses FlyWithWings as its FlyBehavior type.
        flyBehavior = new FlyWithWings();
    }

    public void display() {
        System.out.println("I'm a real Mallard duck");
    }

}

class ModelDuck extends Duck {
    public ModelDuck() {
        flyBehavior = new FlyNoWay();
        quackBehavior = new Quack();
    }

    public void display() {
        System.out.println("I'm a model duck");
    }
}

class FlyRocketPowered implements FlyBehavior {
    public void fly() {
        System.out.println("I'm flying with a rocket!");
    }
}

public class MiniDuckSimulator {
    public static void main(String[] args) {
        Duck mallardDuck = new MallardDuck();
        mallardDuck.performQuack();
        mallardDuck.performFly();

        Duck modelDuck = new ModelDuck();
        modelDuck.performFly();
        modelDuck.setFlyBehavior(new FlyRocketPowered());
        modelDuck.performFly();
    }
}
