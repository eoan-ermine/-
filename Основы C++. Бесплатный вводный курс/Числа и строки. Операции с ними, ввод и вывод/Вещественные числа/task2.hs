main = do
   line1 <- getLine
   let a:b:[] = map (read :: String -> Double) (words line1)
   print $ (truncate (a / b))