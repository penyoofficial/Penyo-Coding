<script lang="ts">
import {
  ElRow,
  ElDivider,
  ElButton,
  ElText,
  ElScrollbar,
  ElTimeline,
  ElTimelineItem,
  ElNotification
} from 'element-plus'
import { regionData } from 'element-china-area-data'

export default {
  name: 'IDCodeGenerator',
  components: {
    ElRow,
    ElDivider,
    ElButton,
    ElText,
    ElScrollbar,
    ElTimeline,
    ElTimelineItem
  },
  data(): {
    condition: {
      area: string[]
      birthday: Date | null
      sex: string
    }
    areas: unknown
    sexs: unknown
    ops: {
      value: string
      timestamp: string
    }[]
  } {
    return {
      condition: {
        area: [],
        birthday: null,
        sex: ''
      },
      areas: regionData,
      sexs: [
        { value: '1', label: '男' },
        { value: '2', label: '女' }
      ],
      ops: []
    }
  },
  methods: {
    newOP() {
      this.ops.unshift({
        value: (() => {
          const area = this.condition.area[2]
          const birthday = ((date: Date) => {
            const year = date.getFullYear().toString()
            const month = (date.getMonth() + 1).toString().padStart(2, '0')
            const day = date.getDate().toString().padStart(2, '0')
            return year + month + day
          })(this.condition.birthday as Date)
          const getOdd = (upper: number): number => {
            const maybeOdd = Math.round(Math.random() * 100) % upper
            if (maybeOdd % 2) return maybeOdd
            return getOdd(upper)
          }
          const sex = ((this.condition.sex ? getOdd(1000) : getOdd(1000) - 1) + '').padStart(3, '0')
          const factors = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
          const code17 = area + birthday + sex
          let sum = 0
          for (let i = 0; i < 17; i++) sum += factors[i] * parseInt(code17[i])
          if (sum % 11 === 2) return code17 + 'X'
          else if (sum % 11 < 2) return code17 + (1 - (sum % 11))
          else return code17 + (12 - (sum % 11))
        })(),
        timestamp: (() => {
          const date = new Date()
          const hours = date.getHours().toString().padStart(2, '0')
          const minutes = date.getMinutes().toString().padStart(2, '0')
          const seconds = date.getSeconds().toString().padStart(2, '0')
          return `${hours}:${minutes}:${seconds}`
        })()
      })
    },
    re(fn: Function, times: number) {
      if (!this.condition.area[2] || !this.condition.birthday || !this.condition.sex) {
        ElNotification.error({
          title: '生成被拒绝！',
          message: '您必须指定出生地、生日和性别！',
          position: 'bottom-right'
        })
        return
      }
      while (times--) fn()
    }
  }
}
</script>

<template>
  <el-row id="conditions">
    <el-cascader
      v-model="condition.area"
      class="c"
      :options="areas"
      :show-all-levels="false"
      placeholder="出生地"
    />
    <el-date-picker v-model="condition.birthday" class="c" type="date" placeholder="生日" />
    <el-cascader v-model="condition.sex" class="c" :options="sexs" placeholder="性别" />
  </el-row>
  <el-row>
    <el-button type="primary" @click="re(newOP, 1)">生成一个</el-button>
    <el-button type="primary" @click="re(newOP, 10)">生成十个</el-button>
    <el-text type="primary" style="margin: 0 3em 0 1em">总数：{{ ops.length }}</el-text>
    <el-button type="warning" @click="ops = []">清空</el-button>
  </el-row>
  <el-divider />
  <el-scrollbar height="320px">
    <el-timeline style="width: 50%; transform: translateX(0.5em)">
      <el-timeline-item
        v-for="op in ops"
        :timestamp="op.timestamp"
        :color="op === ops[0] ? '#0bbd87' : ''"
      >
        {{ op.value }}
      </el-timeline-item>
    </el-timeline>
  </el-scrollbar>
</template>

<style>
#conditions {
  margin-bottom: 1em;
}

#conditions .c {
  margin-right: 1em;
}

#conditions .c:nth-child(2),
#conditions .c:nth-child(3) {
  width: 10em;
}
</style>
