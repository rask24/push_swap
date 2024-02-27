# frozen_string_literal: true

require_relative "./helper/command_helper"
require "descriptive_statistics"

size = 100
iters = 20

results = []

iters.times do
  input = (-10000..10000).to_a.sample(size).map(&:to_s)
  stdout, _stderr, _status = execute_push_swap(*input)
  count = stdout.split("\n").count

  results << count
  stdout, _stderr, _status = execute_checker(*input)
  print "#{count}, #{stdout}"
end

puts "max:     #{results.max}"
puts "min:     #{results.min}"
puts "average: #{results.mean}"
