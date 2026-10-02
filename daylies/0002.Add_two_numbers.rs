// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        
        let mut result: Option<Box<ListNode>> = Some(Box::new(ListNode::new(0)));

        let l1_val: i32 = if l1.is_some() { l1.as_ref().unwrap().val } else { 0 };
        //println!("l1_val: {}", &l1_val);
        let l2_val: i32 = if l2.is_some() { l2.as_ref().unwrap().val } else { 0 };
        //println!("l2_val: {}", &l2_val);

        let mut overflow: u8 = 0;
        let sum: i32 = Self::add(l1_val, l2_val, &mut overflow);
        result.as_mut().unwrap().val = sum;

        let mut depth: u8 = 1;
        let mut ln1: &Option<Box<ListNode>> = &l1.as_ref().unwrap().next;
        let mut ln2: &Option<Box<ListNode>> = &l2.as_ref().unwrap().next;
        //println!("loop!");
        loop {
            if((ln1.is_some() || ln2.is_some() || overflow > 0) && depth <= 100)
            {
                //println!("  overflow: {}", overflow);
                let mut ln1_val: i32 = 0;
                if ln1.is_some() {
                    ln1_val = ln1.as_ref().unwrap().val;
                    //println!("ln1_val: {}", &ln1_val);
                    ln1 = &ln1.as_ref().unwrap().next;
                }

                let mut ln2_val: i32 = 0;
                if ln2.is_some() {
                    ln2_val = ln2.as_ref().unwrap().val;
                    //println!("ln2_val: {}", &ln2_val);
                    ln2 = &ln2.as_ref().unwrap().next;
                }
                
                Self::push(&mut result, Self::add(ln1_val, ln2_val, &mut overflow));
                depth += 1;
            }
            else
            {
                //println!("loop break!");
                break;
            }
        }

        return result;
    }

    pub fn push(listNode: &mut Option<Box<ListNode>>, val: i32) {
        //println!("push() called!");
        match &listNode.as_ref().unwrap().next {
            Some(ln) => { 
                //println!("found next!    current val: {}, next val: {}", listNode.as_ref().unwrap().val, &ln.val);
                Self::push(&mut listNode.as_mut().unwrap().next, val);
            },
            None => { 
                //println!("found no next! current val: {}, val to add: {}", listNode.as_ref().unwrap().val, val);
                let mut newLM: Box<ListNode> = Box::new(ListNode::new(val));
                listNode.as_mut().unwrap().next = Some(newLM);
            },
        }
    }

    pub fn add(x: i32, y: i32, overflow: &mut u8) -> i32 {
        let mut sum: i32 = x + y + i32::from(overflow.cast_signed());
        *overflow = 0;

        if(sum > 9) {
            *overflow = 1;
            sum = sum % 10;
        }

        return sum;
    }
}
