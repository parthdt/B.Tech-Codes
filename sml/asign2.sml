

    (*QUESTION 3 ASSIGNMENT 2*)
    (*considered .x tye no. to be not valid and 0.x is valid*)
    datatype class = INT|FLOAT|FIXED

    fun charToStrList cl = map(fn x => Char.toString x) cl

    fun cc (str1,str2) = Char.toString(String.sub(str1,0))=str2
    fun ccint str = Char.isDigit(String.sub(str,0))
    fun ccintsign str = ccint str orelse Char.toString(String.sub(str,0))="+" orelse Char.toString(String.sub(str,0))="-"

    fun tailcheck [h] = if ccint h then true else false   
                                    | tailcheck (h::t) = if ccint h then tailcheck t else false
    
    fun accept4 [] = NONE
        |accept4 [h] = if ccint h then SOME FLOAT else NONE
        |accept4 (h::t) = if tailcheck (h::t) then SOME FLOAT else NONE
    
    fun accept3 [h] = if ccint h then SOME FIXED else NONE
        |accept3 (h::t) = if (ccint h andalso (cc(hd(t),"e") orelse cc(hd(t),"E"))) then accept4 (tl(t)) else if ccint h then accept3 t else NONE

    fun accept2 [h] = if ccint h then SOME INT else NONE
        |accept2 (h::t) = if (ccint h andalso (cc(hd(t),"e") orelse cc(hd(t),"E"))) then accept4 (tl(t)) else if cc(h,".") then accept3 t else if ccint h then accept2 t else NONE
    
    fun accept1 [h] = if ccint h then SOME INT else NONE
        |accept1 (h::t) = if ccintsign h then accept2 t else NONE

    fun accept str = accept1(charToStrList(String.explode(str)))
    