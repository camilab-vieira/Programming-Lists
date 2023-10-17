package ListaJava.Q1;

public class MainClass {
    
    public static void main(String args[]){
        Game newGame = new Game();
        Car normalCar, hybridCar;
        
        normalCar = new Car("normalCar");
        hybridCar = new HybridCar("hybridCar");
        
        newGame.addCar(normalCar);
        newGame.addCar(hybridCar);
        
        try {
            newGame.getCar("normalCar").setVelocidadeMaxima(250.0);
        } catch (Exception e) {
            e.printStackTrace();
        }
        
        try {
            newGame.getCar("hybridCar").setVelocidadeMaxima(-100.0);
        } catch (Exception e) {
            e.printStackTrace();
        }
        
        try {
            ((HybridCar) newGame.getCar("hybridCar")).changeCurrentState();
        } catch (Exception e) {
            e.printStackTrace();
        }
        
        try {
            newGame.removeCar("normalCar");
        } catch (Exception e) {
            e.printStackTrace();
        }
        
        try {
            newGame.removeCar("normalCar");
        } catch (Exception e) {
            e.printStackTrace();
        }
        
        newGame.printAllAttributes();
    }
}