# frozen_string_literal: true

require_relative "../helper/command_helper"

describe "Error cases for push_swap" do
  it "returns error for non integer inputs" do
    _stdout, stderr, status = execute_push_swap("a", "b", "c")

    expect(stderr).to(eq("Error\n"))
    expect(status.exitstatus).to(eq(1))
  end

  it "returns error for duplicates" do
    _stdout, stderr, status = execute_push_swap("3", "2", "5", "4", "1", "0", "2")

    expect(stderr).to(eq("Error\n"))
    expect(status.exitstatus).to(eq(1))
  end

  it "returns error for overflow" do
    _stdout, stderr, status = execute_push_swap("0", "3", "2", "34578347984", "1")

    expect(stderr).to(eq("Error\n"))
    expect(status.exitstatus).to(eq(1))
  end
end
