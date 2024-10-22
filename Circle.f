\ FORTH Circle Program written by Steve Nwachukwu

: radius ( diameter -- radius)
     dup 2 /    \ Calculating the radius (diameter /2 )

;

: circumference ( diameter -- circumference )
    dup 22 * 7 /  \ Calculating the circumference (diameter * 22) / 7
;

: area ( diameter -- area )
    dup dup * 22 * 28 / 
    \ Calculating the area (diameter * diameter * 22) / 28
;

: circle-calculate ( diameter -- )
       dup 0 = if
           drop
           ." Diameter of zero isn't allowed!" CR 
           exit
        then

        dup 0 < if
            ." Error: Negative input!" CR 
            drop
            exit
        then
        ."	Diameter = " dup . CR 

        radius \ Calculating radius
       ." Radius = " . CR

        circumference \ Calculating circumference
       ." Circumference = " . CR

        area \ Calculating area
        ." Area = " . CR
;
