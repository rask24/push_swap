# frozen_string_literal: true

require_relative "../helper/command_helper"

describe "Corner cases for push_swap" do
  it "does not output operations for already sorted input" do
    stdout, _stderr, status = execute_push_swap("0", "1", "2", "3")
    expect(stdout).to(eq(""))
    expect(status.exitstatus).to(eq(0))
  end
end
