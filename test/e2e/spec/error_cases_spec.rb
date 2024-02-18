# frozen_string_literal: true

require_relative "../helper/command_helper"

describe "Error cases for push_swap" do
  describe "when inputs are not integers" do
    it "reports an error if all arguments are non-integer" do
      _stdout, stderr, status = execute_push_swap("a", "b", "c")

      expect(stderr).to(eq("Error\n"))
      expect(status.exitstatus).to(eq(1))
    end

    it "reports an error if any argument is non-integer" do
      _stdout, stderr, status = execute_push_swap("3", "push_swap", "5", "4", "1", "0", "2")

      expect(stderr).to(eq("Error\n"))
      expect(status.exitstatus).to(eq(1))
    end
  end

  describe "when there are duplicate inputs" do
    it "reports an error if all arguments are the same" do
      _stdout, stderr, status = execute_push_swap("3", "3", "3", "3", "3", "3", "3")

      expect(stderr).to(eq("Error\n"))
      expect(status.exitstatus).to(eq(1))
    end

    it "reports an error if there are any duplicate arguments" do
      _stdout, stderr, status = execute_push_swap("3", "2", "5", "4", "1", "0", "2")

      expect(stderr).to(eq("Error\n"))
      expect(status.exitstatus).to(eq(1))
    end
  end

  it "reports an error for integer overflow" do
    _stdout, stderr, status = execute_push_swap("0", "3", "2", "34578347984", "1")

    expect(stderr).to(eq("Error\n"))
    expect(status.exitstatus).to(eq(1))
  end
end
