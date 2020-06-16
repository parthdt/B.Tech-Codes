exception NotUnsignedIntegers; (*exception for non-unsigned digits*)

(*utility function for checkInputs to check if a number is between 0 and 9*)
fun between0and9 integer = if(integer>=0 andalso integer<=9) then true else false

(*checks if inputs are correct*)
fun checkInputs ([],[])  = true
    |checkInputs (L1 as (h1::t1),L2 as (h2::t2)) = if((between0and9 h1) andalso (between0and9 h2)) then checkInputs(t1,t2) else raise NotUnsignedIntegers

(*converts string to int List*)
fun explodedIntList str  = let val charList = (explode(str))
							in map(fn ch => (Char.ord(ch) - 48)) charList
							end

(*converts int List to string*)                            
fun intListtoString L = let val charList = map(fn ch => (Char.chr(ch+48))) L
                        in implode(charList)
                        end

(*corrects lengths of two lists, adds zeroes where required*)
fun correctList (L1,L2) = if length L1<length L2 then 
                                correctList(0::L1,L2) 
                                else if  length L1>length L2 then correctList(L1,0::L2) 
                                else (L1,L2)

(*pads zeroes to the end*)                                
fun padZeroesBack (L,0) = L
    | padZeroesBack (L,m) = padZeroesBack((L@[0]),m-1)

(*pads zeroes to the beginning*)                                
fun padZeroesAhead (L,0) = L
    | padZeroesAhead (L,m) = padZeroesAhead(0::L,m-1)

fun lengthSame(L1 as h::t,L2 as hn::tn) = 
    if List.length(L1)=List.length(L2) then (L1,L2)
    else if List.length(L1)>List.length(L2) then lengthSame(L1,0::L2)
    else lengthSame(0::L1,L2)

(*splits a list into two lists*)
fun split L = let val size = List.length L
                    
                    val M = List.take(L,(size div 2))
                    val N = List.drop(L,(size div 2))
                    val (m,n) = correctList(M,N)
                in (m,n)
                end

(*adds a list in reverse*)
fun addList ([],[],carry) = if carry=0 then [] else [carry]
    | addList ((h1::t1),(h2::t2),carry) = let val sum = (h1+h2+carry) mod 10;
                                             val car = (h1+h2+carry) div 10;    
                                         in sum::addList(t1,t2,car)
                                         end
                        
(*takes revere into account to add the lists*)
fun finalAdd (L1,L2) =
            let 
                val (L3,L4)=correctList(L1,L2)
            in
             List.rev(addList(List.rev(L3),List.rev(L4),0))
             end

(*removes trailing zeroes in a list*)
fun removeTrailingZeroes [a]= [a]
    |removeTrailingZeroes (L1 as h::t) =
        if h=0 then removeTrailingZeroes (t) else L1

(*find the greater of two lists - used in subtraction on lists*)
fun findGreater ([],[]) = true
    |findGreater ((h1::t1),(h2::t2)) = if h1=h2 then findGreater(t1,t2)
                                      else if h1>h2 then true
                                      else false  

(*simply subtracts each element from two lists one by one*)    
fun subtractList (L1,L2) = if(findGreater(L1,L2)) then ListPair.map(fn(i,j) => (i-j)) (L1,L2)
                           else ListPair.map(fn(i,j) => (i-j)) (L2,L1)

(*if negative elements are left in a list, then it corrects it*)
fun correctListSubtraction [a] = [a]
    |correctListSubtraction (h::t) =  let val newh = if(h<0) then h+10 else h
                                          val newt = if(h<0) then List.update(t,0,List.nth(t,0)-1) else t
                                    
                                        in newh::correctListSubtraction(newt)
                                        end
(*final function to subtract two lists taking both the upper ones into account*)
fun finalSubtract (L1,L2) = 
                    let val(L3,L4)=correctList(L1,L2);
                    in
                    List.rev(correctListSubtraction(List.rev(subtractList(L3,L4))))
                    end

(*function that implements karatsuba algo to two int lists*)                                  
fun karatsuba ([a],[b]) = let val mult = a*b mod 10
                            val carry = a*b div 10
                        in [carry,mult]
                        end            
    | karatsuba (L3 as (h1::t1),L4 as (h2::t2)) = let 

                                                    val (L1,L2) = lengthSame(L3,L4)
                                                    val m=(List.length(L1)+1) div 2;
                                                    val (x1,x0) = split L1;
                                                    val (y1,y0) = split L2;
                                                    val z2 = removeTrailingZeroes(karatsuba(x1,y1));
                                                    val z0 = removeTrailingZeroes(karatsuba(x0,y0));
                                                    val z2andz0 = removeTrailingZeroes(finalAdd(z2,z0));
                                                    val x1andx0 = removeTrailingZeroes(finalAdd(x1,x0));
                                                    val y1andy0 = removeTrailingZeroes(finalAdd(y1,y0));
                                                    val temp = removeTrailingZeroes(karatsuba(x1andx0,y1andy0));
                                                    val z1 = removeTrailingZeroes(finalSubtract(temp,z2andz0));
                                                    val addz2 = padZeroesBack(z2,(2*m));
                                                    val numz0 = List.length(addz2)-List.length(z0);
                                                    val addz0 = padZeroesAhead(z0,numz0);
                                                    val tempz1 = padZeroesBack(z1,m);
                                                    val numz1 = List.length(addz2) - List.length(tempz1);
                                                    val addz1 = padZeroesAhead(tempz1,numz1);
                                                    val z1z0 = finalAdd(addz0,addz1);
                                                    val z2z1z0 = finalAdd(z1z0,addz2);
                                                    in
                                                        z2z1z0
                                                    end

(*final karatsuba function - which is to be run, applying karatsuba algo on two strings of numbers*)                                                    
fun finalKaratsuba (str1,str2) = let val list1 =removeTrailingZeroes(explodedIntList(str1))
                                     val list2 = removeTrailingZeroes(explodedIntList(str2))
                                     in
                                        if checkInputs(list1,list2) then 
                                            intListtoString(removeTrailingZeroes(karatsuba(list1,list2)))
                                        else raise NotUnsignedIntegers
                                    end