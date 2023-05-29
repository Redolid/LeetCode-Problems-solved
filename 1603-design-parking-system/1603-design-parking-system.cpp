class ParkingSystem {
private:
    int availableBig;
    int availableMedium;
    int availableSmall;

public:
    ParkingSystem(int big, int medium, int small) {
        availableBig = big;
        availableMedium = medium;
        availableSmall = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1 && availableBig > 0) {
            availableBig--;
            return true;
        } else if (carType == 2 && availableMedium > 0) {
            availableMedium--;
            return true;
        } else if (carType == 3 && availableSmall > 0) {
            availableSmall--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */