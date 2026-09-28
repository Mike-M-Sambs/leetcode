impl Solution {
    pub fn max_depth(s: String) -> i32 {
        let mut depth: i32 = 0;
        let mut current_depth: i32 = 0;

        for (idx, c) in s.char_indices() 
        { 
            //println!("char: {}  in idx: {}",c, idx);

            if(c == '(') 
            {
                //println!("parenthesis found at idx {}", idx);
                current_depth += 1;
                if(current_depth > depth)
                {
                   depth = current_depth; 
                }
                //println!("current_depth: {}", current_depth);
            }
            if(c == ')') 
            {
                //println!("parenthesis closed at idx {}", idx);
                current_depth -= 1;
                //println!("current_depth: {}", current_depth);
            }
        }
        //println!("depth: {}", depth);
        
        return depth;
    }
}
