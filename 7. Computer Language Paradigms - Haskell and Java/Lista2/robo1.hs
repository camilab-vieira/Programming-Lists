data Command = Forward Int | Backward Int | TurnLeft | TurnRight 
               deriving (Eq, Show, Read)
             
data Direction = North | South | West | East
                 deriving (Eq, Read, Show)

destination :: (Int,Int) -> [Command] -> (Int,Int)
destination pair list = destinationAux North pair list

destinationAux :: Direction -> (Int,Int) -> [Command] -> (Int,Int)
destinationAux dir pair [] = pair 
destinationAux dir (a, b) ((Forward n):xs) | dir == North = destinationAux North (a, (b+n)) xs
                                         | dir == South = destinationAux South (a, (b-n)) xs
                                         | dir == East = destinationAux East ((a+n), b) xs
                                         | dir == West = destinationAux West ((a-n), b) xs
destinationAux dir (a, b) ((Backward n):xs) | dir == North = destinationAux North (a, (b-n)) xs
                                         | dir == South = destinationAux South (a, (b+n)) xs
                                         | dir == East = destinationAux East ((a-n), b) xs
                                         | dir == West = destinationAux West ((a+n), b) xs
destinationAux dir pair ((TurnLeft):xs)  | dir == North = destinationAux West pair xs
                                         | dir == South = destinationAux East pair xs
                                         | dir == East = destinationAux North pair xs
                                         | dir == West = destinationAux South pair xs
destinationAux dir pair ((TurnRight):xs) | dir == North = destinationAux East pair xs
                                         | dir == South = destinationAux West pair xs
                                         | dir == East = destinationAux South pair xs
                                         | dir == West = destinationAux North pair xs

main = do
       a <- getLine
       b <- getLine
       let result = destination (read a) (read b)
       print result