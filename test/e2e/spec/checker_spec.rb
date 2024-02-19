# frozen_string_literal: true

require_relative "../helper/command_helper"

describe("Performance test for push_swap") do
  [1, 2, 3, 4, 5, 10, 50, 100, 200, 500, 1000].each do |size|
    it "measures operations for random input of size #{size}" do
      input = (-10000..10000).to_a.sample(size).map(&:to_s)
      _stdout, _stderr, status = execute_push_swap(*input)
      expect(status.exitstatus).to(eq(0))

      stdout, _stderr, status = execute_checker(*input)
      expect(status.exitstatus).to(eq(0))
      expect(stdout).to(eq("OK\n"))
    end
  end
end
