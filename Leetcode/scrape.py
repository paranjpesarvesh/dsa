import requests
import json

OUTPUT_FILE = "problems.json"
LEETCODE_API = "https://leetcode.com/api/problems/all/"

def scrape_problems():
    print("Fetching problem set from LeetCode...")
    resp = requests.get(LEETCODE_API)
    resp.raise_for_status()
    data = resp.json()

    problems = []
    for p in data["stat_status_pairs"]:
        stat = p["stat"]
        problems.append({
            "id": stat["frontend_question_id"],
            "title": stat["question__title"],
            "slug": stat["question__title_slug"],
            "difficulty": p["difficulty"]["level"],  # 1=Easy,2=Medium,3=Hard
            "paid_only": p["paid_only"],
            "is_favor": p["is_favor"],
        })

    with open(OUTPUT_FILE, "w") as f:
        json.dump(problems, f, indent=2)

    print(f"✅ Saved {len(problems)} problems to {OUTPUT_FILE}")

if __name__ == "__main__":
    scrape_problems()

