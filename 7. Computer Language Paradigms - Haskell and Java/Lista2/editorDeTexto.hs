data Cmd = Cursor Int
           | Backspace Int
           | Delete Int
           | Insert String
           deriving (Read)
 
editText :: String -> [Cmd] -> String
editText str ((Cursor x):xs) = editTextCursor 0 x str xs
editText str ((Backspace x):xs) = editTextBackspace 0 x str xs
editText str ((Delete x):xs) = editTextDelete 0 x str xs
editText str ((Insert x):xs) = editTextInsert 0 x str xs

editTextCursor :: Int -> Int -> String -> [Cmd] -> String
editTextCursor cursor n str [] = str
editTextCursor cursor n str ((Cursor x):xs) = editTextCursor (cursor + n) x str xs
editTextCursor cursor n str ((Backspace x):xs) = editTextBackspace (cursor + n) x str xs
editTextCursor cursor n str ((Delete x):xs) = editTextDelete (cursor + n) x str xs
editTextCursor cursor n str ((Insert x):xs) = editTextInsert (cursor + n) x str xs

editTextBackspace :: Int -> Int -> String -> [Cmd] -> String
editTextBackspace cursor n str [] = ((take (cursor-n) str) ++ (drop cursor str))
editTextBackspace cursor n str ((Cursor x):xs) = editTextCursor (cursor-n) x ((take (cursor-n) str) ++ (drop cursor str)) xs
editTextBackspace cursor n str ((Backspace x):xs) = editTextBackspace (cursor-n) x ((take (cursor-n) str) ++ (drop cursor str)) xs
editTextBackspace cursor n str ((Delete x):xs) = editTextDelete (cursor-n) x ((take (cursor-n) str) ++ (drop cursor str)) xs
editTextBackspace cursor n str ((Insert x):xs) = editTextInsert (cursor-n) x ((take (cursor-n) str) ++ (drop cursor str)) xs 

editTextDelete :: Int -> Int -> String -> [Cmd] -> String
editTextDelete cursor n str [] = ((take cursor str) ++ (drop (cursor+n) str))
editTextDelete cursor n str ((Cursor x):xs) = editTextCursor cursor x ((take cursor str) ++ (drop (cursor+n) str)) xs
editTextDelete cursor n str ((Backspace x):xs) = editTextBackspace cursor x ((take cursor str) ++ (drop (cursor+n) str)) xs
editTextDelete cursor n str ((Delete x):xs) = editTextDelete cursor x ((take cursor str) ++ (drop (cursor+n) str)) xs
editTextDelete cursor n str ((Insert x):xs) = editTextInsert cursor x ((take cursor str) ++ (drop (cursor+n) str)) xs 

editTextInsert :: Int -> String -> String -> [Cmd] -> String
editTextInsert cursor n str [] = ((take cursor str) ++ n ++ (drop cursor str))
editTextInsert cursor n str ((Cursor x):xs) = editTextCursor (cursor) x ((take cursor str) ++ n ++ (drop cursor str)) xs
editTextInsert cursor n str ((Backspace x):xs) = editTextBackspace (cursor) x ((take cursor str) ++ n ++ (drop cursor str)) xs
editTextInsert cursor n str ((Delete x):xs) = editTextDelete (cursor) x ((take cursor str) ++ n ++ (drop cursor str)) xs
editTextInsert cursor n str ((Insert x):xs) = editTextInsert (cursor) x ((take cursor str) ++ n ++ (drop cursor str)) xs 

main = do
       a <- getLine
       b <- getLine
       let result = editText a (read b)
       print result