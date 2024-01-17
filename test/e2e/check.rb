# frozen_string_literal: true

a = [1, 2, 3, 4, 5]

a.permutation.to_a.each do |array|
  str = +'./push_swap'
  array.each do |item|
    str << " #{item}"
  end
  str << ' | wc -l | bc'
  puts str
  system str, exception: true
  puts "\n"
end
