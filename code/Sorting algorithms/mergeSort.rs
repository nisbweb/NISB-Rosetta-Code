fn sort(array: &mut [i32]) {
	let middle = array.len() / 2;
	if array.len() < 2 {
	  return; 
	}
  
	let mut sorted = array.to_vec();
  
	sort(&mut array[..middle]);
	sort(&mut array[middle..]);
	merge(&array[..middle], &array[middle..], &mut sorted);
	array.copy_from_slice(&sorted); 
}

fn merge(l_arr: &[i32], r_arr: &[i32], sorted: &mut [i32]) {
	let (mut left, mut right, mut i) = (0, 0, 0);
	while left < l_arr.len() && right < r_arr.len() {
	  if l_arr[left] <= r_arr[right] {
		sorted[i] = l_arr[left];
		i += 1;
		left += 1;
	  } else {
		sorted[i] = r_arr[right];
		i += 1;
		right += 1;
	  }
	}
  
	if left < l_arr.len() {
	  sorted[i..].copy_from_slice(&l_arr[left..]);
	}
  
	if right < r_arr.len() {
	  sorted[i..].copy_from_slice(&r_arr[right..]);
	}
}


fn main(){
	let mut input : [i32;9] = [0,23,1,3,24,9,12,25,68];
	sort(&mut input);
	for item in input.iter() {
		print!("{} ",item);
	}
}