
(* Q1 assignment 2 *)
datatype 'a RE = Nil 
        | Eps 
        | Atom of 'a 
        | Dot of 'a RE * 'a RE 
        | Or of 'a RE * 'a RE 
        | Star of 'a RE

fun toString Nil="Nil"
        |toString (Dot (x,y))=implode([#"("]@explode(toString(x))@[#"."]@explode(toString(y))@[#")"])
        |toString (Or (x,y))=implode([#"("]@explode(toString(x))@[#"|"]@explode(toString(y))@[#")"])
        |toString Eps="Eps"
        |toString (Star (x))=implode(explode(toString(x))@[#"*"])  
        |toString (Atom (x))=x 
            