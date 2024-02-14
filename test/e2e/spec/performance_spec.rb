# frozen_string_literal: true

require_relative "../helper/command_helper"

describe("Performance test for push_swap") do
  size = 500
  it "measures operations for random input of size #{size}" do
    results = []
    20.times do
      input = (0...500).to_a.shuffle.map(&:to_s)
      stdout, _stderr, status = execute_push_swap(*input)
      expect(status.exitstatus).to(eq(0))
      results << stdout.split("\n").count

      stdout, _stderr, status = execute_checker(*input)
      expect(status.exitstatus).to(eq(0))
      expect(stdout).to(eq("OK\n"))
      print "\e[32m.\e[0m"
    end
    max_operations = results.max
    min_operations = results.min
    average_operations = results.sum / results.size.to_f
    print "\n"
    print "For size #{size}: Max: #{max_operations}, Min: #{min_operations}, Average: #{average_operations}"
  end
end
