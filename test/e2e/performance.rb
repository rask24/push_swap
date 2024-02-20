# frozen_string_literal: true

require_relative "helper/command_helper"
require "descriptive_statistics"

size = 500
iters = 50

results = []

iters.times do
  input = (0...size).to_a.shuffle.map(&:to_s)
  stdout, _stderr, _status = execute_push_swap(*input)
  results << stdout.split("\n").count

  print "\e[32m.\e[0m"
end

puts "\nFor size #{size}: Max: #{results.max}, Min: #{results.min}, Average: #{results.mean}, SD: #{results.standard_deviation.round(2)}" # rubocop:disable Layout/LineLength
