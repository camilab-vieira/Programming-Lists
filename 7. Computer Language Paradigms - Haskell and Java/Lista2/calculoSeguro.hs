import Prelude hiding (Maybe (..))
import Data.Char

data Maybe a = Just a |
               Nothing
               deriving(Show)

zero = ord '0'
aMin = ord 'a'

safeCalc :: String -> IO ()
safeCalc str | op == "sum" = putStr (show(Just (x+y)))
             | op == "sub" = putStr (show (Just (x-y)))
             | op == "mul" = putStr (show (Just (x*y)))
             | op == "div" && y /= 0 = putStr (show (Just (div x y)))
             |otherwise = putStr (show (f Nothing))
  where x = getNumber str 0
        y = getSndNumber str
        op = getString str
   
f :: Integral t => Maybe t -> Maybe t
f x = x
     
getNumber :: String -> Int -> Int
getNumber [] n = n
getNumber (x:xs) n | ord(x) < aMin = getNumber xs (n*10+(ord(x)-zero))
                   | otherwise = n

getString :: String -> String
getString (x:xs) | ord(x) < aMin = getString xs 
                 | otherwise = take 3 (x:xs)

getSndNumber :: String -> Int
getSndNumber [] = 0 
getSndNumber (x:y:xs) | ord(x) > aMin && ord(y) < aMin = getNumber (y:xs) 0 
                        | otherwise = getSndNumber (y:xs)

main = do
       a <- getLine
       safeCalc a