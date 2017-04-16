package pond.duck;
public class MallardDuck extends Duck {

    public MallardDuck() {
        // A mallardDuck uses the Quack class to handle its quack, so when performQuack is called,
        // the responsibility for the quack is delegated to the Quack object and we get a real quack.
        quackBehavior = new Quack();
        // it uses FlyWithWings as its FlyBehavior type.
        flyBehavior = new FlyWithWings();
    }

    public void displace() {
        System.out.println("I'm a real Mallard duck");
    }

}
