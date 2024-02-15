# frozen_string_literal: true

require_relative "helper/command_helper"

size = 500
results = []

100.times do
  input = (0...size).to_a.shuffle.map(&:to_s)
  stdout, _stderr, _status = execute_push_swap(*input)
  results << stdout.split("\n").count

  print "\e[32m.\e[0m"
end

max_operations = results.max
min_operations = results.min
average_operations = results.sum / results.size.to_f

puts "\nFor size #{size}: Max: #{max_operations}, Min: #{min_operations}, Average: #{average_operations}"
