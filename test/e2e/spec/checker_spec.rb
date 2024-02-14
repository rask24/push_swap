# frozen_string_literal: true

require_relative "../helper/command_helper"

describe("Performance test for push_swap") do
  [5, 10, 50, 100, 200, 500, 1000].each do |size|
    it "measures operations for random input of size #{size}" do
      results = []
      input = (0...size).to_a.shuffle.map(&:to_s)
      stdout, _stderr, status = execute_push_swap(*input)
      expect(status.exitstatus).to(eq(0))
      results << stdout.split("\n").count

      stdout, _stderr, status = execute_checker(*input)
      expect(status.exitstatus).to(eq(0))
      expect(stdout).to(eq("OK\n"))
    end
  end
end
