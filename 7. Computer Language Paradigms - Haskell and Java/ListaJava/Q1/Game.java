package ListaJava.Q1;

import java.util.ArrayList;
import java.util.List;

public class Game {

    private List<Car> possibleCars;

    public Game(){
        possibleCars = new ArrayList<Car>();
    }

    public void setPossibleCars(List<Car> possibleCars){
        this.possibleCars = possibleCars;
    }

    public List<Car> getPossibleCars(){
        return this.possibleCars;
    }

    public void addCar(Car car){
        this.possibleCars.add(car);
    }

    public void removeCar(String ID) throws Exception{
        for(Car car : this.possibleCars){
            if(car.getID().equals(ID)){
                this.possibleCars.remove(this.possibleCars.indexOf(car));
                return;
            }
        }
        throw new Exception("Carro não está na lista");
    }

    public Car getCar(String ID) throws Exception{
        for(Car car : this.possibleCars){
            if(car.getID().equals(ID)){
                return car;
            }
        }

        throw new Exception("Carro não está na lista");
    }

    public void printAllAttributes(){
        for(Car car : this.possibleCars){
            System.out.println(car.getID());
            System.out.println(car.getVelocidadeMaxima());
            System.out.println(car.getPotencia());
        }
    }
}